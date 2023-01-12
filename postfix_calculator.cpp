#include<iostream>
#include<cstring>
#include<stack>
#include<math.h>

#include<stdio.h>


 
using namespace std;


int getWeight(char ch) {
   switch (ch) {
   	  case'^':return 4;
      case '/':return 3;
      case '*': return 2;
      case '+':
      case '-': return 1;
      case '(':
      case ')': return 5;
      default : return 0;
   }
}

// convert infix expression to postfix 
void infix2postfix(char infix[], char postfix[], int size) {
   stack<char> s;
   int weight;
   int i = 0;
   int k = 0;
   char ch; 
   while (i < size) {
      ch = infix[i];
      if (ch == '(') {
         s.push(ch);
         i++;
         continue;
      }
      if (ch == ')') {
         while (!s.empty() && s.top() != '(') {
            postfix[k++] = s.top();
            s.pop();

         }
        
         if (!s.empty()) {
            s.pop();
         }
         i++;
                  continue;
      }
      weight = getWeight(ch);
      if (weight == 0) {
         // we saw an operand
         postfix[k++] = ch;

      }
      else {
         // we saw an operator
         if (s.empty()) {
          
            s.push(ch);
         }
         else {
            while (!s.empty() && s.top() != '(' &&
                  weight <= getWeight(s.top())) {
               postfix[k++] = s.top();
               s.pop();

            }
          
            s.push(ch);
         }
      }
      i++;
   } 
   while (!s.empty()) {
      postfix[k++] = s.top();
      s.pop();
   }
   postfix[k] = 0; 
}

// returns the value

int eval(int op1, int op2, char operate) {
   switch (operate) {
      case '*': return op2 * op1;
      case '/': return floor(op2 / op1);
      case '+': return op2 + op1;
      case '-': return op2 - op1;
      case '^': return pow(op2,op1);
      default : return 0;
   }
}

int evalPostfix(char postfix[], int size) {
   stack<int> s;
   int i = 0;
   char ch;
   int val;
   while (i < size) {
      ch = postfix[i];
      if (isdigit(ch)) {
         s.push(ch-'0');
      }
      else {
   
         int op1 = s.top();
         s.pop();
         int op2 = s.top();
         s.pop();
         val = eval(op1, op2, ch);
      
         s.push(val);
      }
      i++;
   }
   return val;
}



int main() {
   char infix[] = " ";
   cin>>infix;
   int size = strlen(infix);
   char postfix[size];
   infix2postfix(infix,postfix,size);
  
  // cout<<postfix<<endl;
   
   int size1 = sizeof(postfix);
   int val = evalPostfix(postfix, size);
   cout<<val<<endl;

   return 0;
}

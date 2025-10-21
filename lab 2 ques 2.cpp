#include <stdio.h> 
#include <ctype.h> 
#define SIZE 100 
char stack[SIZE]; 
int top = -1; 
void push(char c) { 
stack[++top] = c; 
}
char pop() { 
return stack[top--]; 
} 
int precedence(char op) { 
if(op == '^') return 3; 
if(op == '*' | op == '/') return 2; 
if(op == '+' | op == '-') return 1; 
return 0; 
} 
int main() { 
char infix[SIZE], postfix[SIZE]; 
int i, j = 0; 
char ch; 
printf("Enter infix expression: "); 
scanf("%s", infix); 
for(i = 0; infix[i] != '\0'; i++) { 
ch = infix[i]; 
if(isalnum(ch)) { 
postfix[j++] = ch; 
} 
else if(ch == '(') { 
push(ch); 
} 
else if(ch == ')') { 
// operand 
while(top != -1 && stack[top] != '(') { 
postfix[j++] = pop();
} 
pop(); // remove '(' 
} 
else { // operator 
while(top != -1 && precedence(stack[top]) >= precedence(ch)) { 
postfix[j++] = pop(); 
} 
push(ch); 
} 
} 
while(top != -1) { 
postfix[j++] = pop(); 
} 
postfix[j] = '\0'; 
printf("Postfix expression: %s\n", postfix); 
return 0; 
} 
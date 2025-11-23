Aim:
To convert a given infix expression to its equivalent postfix expression using a stack.

Algorithm:
  
1.Create an empty stack for operators.
2.Read the infix expression from left to right (character by character).
3.If the character is an operand (letter or digit), append it to the postfix output.
4.If the character is '(', push it onto the stack.
5.If the character is ')', pop from the stack and append to postfix until '(' is popped.
6.If the character is an operator (+ - * / ^), then:
   While the stack is not empty and top of stack has operator of higher or equal precedence (for ^ you may treat as right-associative if needed), pop it and append to postfix.
   Push the current operator onto the stack.
   After the entire infix is processed, pop any remaining operators from the stack and append to postfix.
7.Terminate postfix string and display it.

Program:
#include <stdio.h>
#include <ctype.h>     
#include <string.h>   
#define MAX 100
char stack[MAX];
int top = -1;
int isEmpty() 
{
    return top == -1;
}
void push(char item) 
{
    if (top >= MAX - 1) 
    {
        printf("stack overflow\n");
        return;
    }
    stack[++top] = item;
}
char pop() 
{
    if (isEmpty()) 
    {
        printf("stack underflow\n");
        return '\0';
    }
    return stack[top--];
}
char peek() 
{
    if (isEmpty()) return '\0';
    return stack[top];
}
int precedence(char item) 
{
    if (item == '^') return 3;                     
    else if (item == '*' || item == '/') return 2; 
    else if (item == '+' || item == '-') return 1;
    else return 0;
}
int main() 
{
    char infix[MAX], postfix[MAX];
    int i, k = 0;
    char ch, temp;
    printf("Enter Infix expression: ");
    scanf("%s", infix);
    for (i = 0; i < (int)strlen(infix); i++) 
    {
        ch = infix[i];
        if (isalnum(ch)) 
        {         
            postfix[k++] = ch;
        } 
        else if (ch == '(') 
        {   
            push(ch);
        } 
        else if (ch == ')')
        {    
            while (!isEmpty() && (temp = pop()) != '(')
            {
                postfix[k++] = temp;
            }
        } 
        else 
        {
            while (!isEmpty() && precedence(peek()) >= precedence(ch)) 
            {
                postfix[k++] = pop();
            }
            push(ch);  
        }
    }
    while (!isEmpty()) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';   
    printf("Postfix expression: %s\n", postfix);
    return 0;
}

Output:
Enter Infix expression: (A+B)^D+E/(F+A*D)+C
postfix expression: AB+D^E F A D * + / + C +

Result:
The given infix expression is successfully converted into its equivalent postfix expression using stack operations.
The program correctly applies the rules of operator precedence and parentheses handling, and displays the postfix form of the entered infix expression.

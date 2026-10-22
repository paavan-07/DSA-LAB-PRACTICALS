// Practical 4 - I : Infix to Postfix Conversion.

#include<iostream>
using namespace std;

#define size 20
char stack[size];
int top=-1;

void push(char ele)
{
    if(top == size-1)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        top++;
        stack[top] = ele;
    }
}

char pop()
{
    if(top == -1)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        char x = stack[top];
        top--;
        return x;
    }
}

int precedance(char ch)
{
    if(ch == '+' || ch == '-')
    {
        return 1;
    }
    else if(ch == '*' || ch == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) 
{
    int i = 0, j = 0;
    
    while(infix[i] != '\0') 
    {
        if (precedance(infix[i]) == 0)
        {
            postfix[j++] = infix[i];
        }
        else
        {
            while (top != -1 && precedance(stack[top]) >= precedance(infix[i]))
            {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }
    
    while (top != -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; 
}

int main()
{
    char infix[20], postfix[20];

    cout << "Enter the infix expression: ";
    cin >> infix;

    infixToPostfix(infix, postfix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
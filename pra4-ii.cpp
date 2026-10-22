// Practical - 4 - II : Write a program to evaluate a postfix expression.

#include<iostream>
using namespace std;

#define size 20
int stack[size];
int top=-1;

void push(int ele)
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

int pop()
{
    if(top == -1)
    {
        cout << "Stack Underflow" << endl;
        return 0;
    }
    else
    {
        int x = stack[top];
        top--;
        return x;
    }
}

int isDigit(char c)
{
    if(c >= '0' && c <= '9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char exp[size];
    cout << "Enter the expression: ";
    cin >> exp;

    cout << "POstfix expression: " << exp << endl;

    for(int i=0; exp[i]!='\0'; i++)
    {
        int ch = exp[i];
        if(isDigit(ch) == 1)
        {
            push(ch - '0');
        }
        else if (ch=='+' || ch=='-' || ch=='*' || ch=='/')
        {
            int op2 = pop();
            int op1 = pop();
            int result = 0;
            switch(ch)
            {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    if(op2 == 0)
                    {
                        cout << "Division by zero error!" << endl;
                        return 1;
                    }
                    else
                    {
                        result = op1 / op2;
                    }
                    break;
            }
            push(result);
        }        
    }
    cout << "Result: " << pop() << endl;
    return 0;
}
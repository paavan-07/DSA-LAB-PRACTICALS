// Practical - 3 : Write a program to implement stack using array.Demonstrate the following operations on stack: push( ), pop( ), peek( ) and display( ).

#include<iostream>
using namespace std;

#define size 5
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

int flag = 1;
void pop()
{
    if(top == -1)
    {
        cout << "Stack Underflow" << endl;
        flag = 0;
    }
    else
    {
        int x = stack[top];
        top--;
    }
}

void peep()
{
    if(top == -1)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Top element is: " << stack[top] << endl;
    }
}

void display()
{
    if(top == -1 && flag == 1)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        for(int i=top; i>=0; i--)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}


int main()
{   
    peep();
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    //push(60);                             stack overflow
    display();
    peep();

    pop();
    pop();
    pop();
    pop();
    pop();
    //pop();                                stack underflow
    display();
    return 0;
}
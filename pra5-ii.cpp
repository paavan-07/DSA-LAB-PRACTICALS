// Practical - 5 - II : Write a program to implement a circular queue using array and perform enqueue( ), dequeue( ) and display( ) operation.

#include<iostream>
using namespace std;

#define size 5
int queue[size];
int f = -1, r = -1;

void cenqueue(int ele)
{
    if((r+1)%size == f)
    {
        cout << "Queue Overflow" << endl;
    }
    else
    {
        r = (r+1)%size;
        if(f == -1)
        {
            f++;
        }
        queue[r] = ele;
    }
}

void cdequeue()
{
    if(f == -1)
    {
        cout << "Queue Underflow" << endl;
    }
    else
    {
        int temp = queue[f];
        if(f == r)
        {
            f = -1;
            r = -1;
        }
        else
        {
            f = (f+1)%size;
        }
    }
}

void display()
{
    if(f == -1)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    if(f <= r)
    {
        cout << "Queue = ";
        for(int i=f; i<=r; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Queue = ";
        for(int i=f; i<size; i++)
        {
            cout << queue[i] << " ";
        }
        for(int i=0; i<=r; i++)
        {
            cout << queue[i] << " ";
        }
    }
}

int main()
{
    cenqueue(10);
    cenqueue(20);
    cenqueue(30);
    display();

    cenqueue(40);
    cenqueue(50);
    display();

    cdequeue();
    cdequeue();
    display();

    cdequeue();
    cdequeue();
    display();  
    
    cenqueue(60);
    cenqueue(70);
    display();

    return 0;
}
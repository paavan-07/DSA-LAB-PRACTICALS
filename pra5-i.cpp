// Practical - 5 - I : Write a program to implement a simple queue using array and perform enqueue( ), dequeue( ) and display( ) operation.

#include<iostream>
using namespace std;
#define size 5
int queue[size];
int f = -1, r = -1;

void enqueue(int ele)
{
    if(r == size-1)
    {
        cout << "Queue Overflow" << endl;
    }
    else
    {
        r++;
        if(f == -1)
        {
            f++;
        }
        queue[r] = ele;
    }
}

int flag = 1;
void dequeue()
{
    if(f == -1)
    {
        cout << "Queue Underflow" << endl;
        flag = 0;
    }
    else
    {
        int temp = queue[f];
        if(f == r)
        {
            f = r = -1;
        }
        else
        {
            f++;
        }
    }
}

void display()
{
    if(flag == 0)
    {
        return;
    }
    else if(f == -1)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    else
    {
        cout << "Queue = ";
        for(int i=f; i<=r; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    enqueue(10);
    enqueue(11);
    enqueue(12);
    display();
    cout << endl;

    enqueue(13);
    enqueue(14);
    //enqueue(15);                     Overflow
    display();
    cout << endl;

    dequeue();
    dequeue();
    dequeue();
    display();
    cout << endl;

    dequeue();
    dequeue();
    //dequeue();                       Underflow
    display();
    return 0;
}
//Problem Statement-2 (B)
//Demonstrate the concept of Call by Value and Call by Reference

//Code: 
#include <iostream>
using namespace std;

void callByValue(int x)
{
    x = x + 5;
    cout << "Value inside callByValue: " << x << endl;
}

void callByReference(int &x)
{
    x = x + 5;
    cout << "Value inside callByReference: " << x << endl;
}

int main()
{
    int a = 15;
    int b = 15;

    cout << "Before callByValue: " << a << endl;
    callByValue(a);
    cout << "After callByValue: " << a << endl;

    cout << endl;

    cout << "Before callByReference: " << b << endl;
    callByReference(b);
    cout << "After callByReference: " << b << endl;

    return 0;
}

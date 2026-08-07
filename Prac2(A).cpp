//Practical-2
//Problem Statement-1 (A)
//Write a program to print Array Elements in Reverse Order Using Dynamic Memory Allocation. 

//Code: 
#include <iostream>
using namespace std;

int main()
{  int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter " << n << " elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Array in reverse order: ";

    for (int i = n - 1; i >= 0; i--)
    {
        cout << *(arr + i) << " ";
    }

    delete[] arr;
    return 0;
}

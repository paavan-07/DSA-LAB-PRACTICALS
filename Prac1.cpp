// Practical-1
//Write a program to create an array and demonstrate insertion, deletion, 
//traversal, and search operations. 

#include <iostream>
using namespace std;

int main() {
    int arr[20], n;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    
    cout << "Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

cout<<endl<<"************************************************************************"; 

    int pos, value;
    cout << "\nEnter position for insertion: ";
    cin >> pos;
    cout << "Enter the value: ";
    cin >> value;

    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];

    arr[pos] = value;
    n++;

    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

cout<<endl<<"************************************************************************"; 

    cout << "\nEnter position you want to delete: ";
    cin >> pos;

    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];

    n--;

    cout << "Array after deletion: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

cout<<endl<<"************************************************************************"; 

    int key;
    cout << "\nEnter the element you want to search: ";
    cin >> key;

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at index " << i;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Sorry! Element not found";

    return 0;
}


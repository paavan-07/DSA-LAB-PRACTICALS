// Practical - 6 : Write a program to implement a singly linked list and perform the following operations :
            // i) Insert a new node (at the beginning , at the end , after a given node).
            // ii) Delete a node (first node , last node , node after a given node).
            // iii) Display all the nodes.

#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int data;
    Node* next;

    // Constructor
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

// Linked List class
class LinkedList
{
private:
    Node* head;

public:

    // Constructor
    LinkedList()
    {
        head = NULL;
    }

    // Display linked list
    void display()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
// Insert at Beginning  
  void insertAtBeginning(int value)
  {
      Node *newNode = new Node(value);
      newNode -> next=head;
      head = newNode;
  }
    // Insert at end
    void insertAtEnd(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Insert at a particular position
    void insertAtPosition(int value, int position)
    {
        Node* newNode = new Node(value);

        // Position 1 means beginning
        if (position == 1)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;

        // Move to node before required position
        for (int i = 1; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        // Invalid position
        if (temp == NULL)
        {
            cout << "Invalid position!" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
// Delete from the Beginning    
    void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    
    Node* temp = head;
    head = head->next;
    delete temp;
}
// Delete from End
void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    
    // If there is only one node
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    
    delete temp->next;
    temp->next = NULL;
}
// Delete from Position
    void deleteAtPosition(int position) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    
    // Deleting the head node (Position 1)
    if (position == 1) {
        deleteFromBeginning();
        return;
    }
    
    Node* temp = head;
    // Traverse to the node immediately before the position to delete
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    // Position is out of bounds
    if (temp == NULL || temp->next == NULL) {
        cout << "Invalid position!" << endl;
        return;
    }
    
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}
};


int main()
{
    // Creating object of LinkedList class
    LinkedList list;

    // Insert at beginning
    list.insertAtBeginning(20);
    list.insertAtBeginning(10);

    cout << "After insertion at beginning:" << endl;
    list.display();

    // Insert at end
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    cout << "\nAfter insertion at end:" << endl;
    list.display();

    // Insert in middle
    list.insertAtPosition(25, 3);

    cout << "\nAfter insertion at position 3:" << endl;
    list.display();
    
    //Delete From Beginning
    list.deleteFromBeginning();
     cout<<"Deletion from beginning"<<endl;
    list.display();
    
    //Delete From End
   list.deleteFromEnd();
   cout<<"Deletion from End"<<endl;
   list.display();
   
   //Delete At Position
   list.deleteAtPosition(2);
   cout<<"Deletion at Position"<<endl;
   list.display();
   

    return 0;
}
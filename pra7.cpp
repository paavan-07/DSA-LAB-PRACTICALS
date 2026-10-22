// Practical - 7 : Write a program to implement a singly circular linked list and perform the following operations :
            // i) Insert a new node (at the beginning , at the end , after a given node).
            // ii) Delete a node (first node , last node , node after a given node).
            // iii) Display all the nodes.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class CircularList
{
private:
    Node* head;

public:

    CircularList()
    {
        head = NULL;
    }

    // Insert at beginning
    void insertAtBeginning(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }
    //Insert after a given node
    void insertAfter(int targetValue, int newValue) {
    if (head == NULL) {
        return;
    }

    Node* temp = head;
   
    // Search for the node with targetValue
    do {
        if (temp->data == targetValue) {
            Node* newNode = new Node(newValue);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);
}
    void deleteFromBeginning() {
    // 1. Check if the list is empty
    if (head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    // 2. Case 1: List has only one node
    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    // 3. Case 2: List has multiple nodes
    Node* temp = head;        
    Node* last = head;

    // Find the last node to update its next pointer
    while (last->next != head) {
        last = last->next;
    }

    head = head->next;          
    last->next = head;        
    delete temp;              
}
    void deleteFromEnd() {
    // 1. Check if the list is empty
    if (head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    // 2. Case 1: List has only one node
    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    // 3. Case 2: List has multiple nodes
    Node* current = head;
    Node* previous = NULL;

    // Traverse until current points to the last node
    while (current->next != head) {
        previous = current;
        current = current->next;
    }

    // Link second-to-last node back to head
    previous->next = head;

    // Free memory of the old last node
    delete current;
}
    void deleteAfter(int targetValue) {
    // 1. Check if list is empty
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;

    // 2. Search for the node with targetValue
    do {
        if (temp->data == targetValue) {
            Node* nodeToDelete = temp->next;

            // Edge Case: If the target's next node is itself (1-node list)
            if (nodeToDelete == temp) {
                cout << "Only one node exists, nothing to delete after it." << endl;
                return;
            }

            // Update pointers to bypass nodeToDelete
            temp->next = nodeToDelete->next;

            // If the deleted node was head, move head pointer
            if (nodeToDelete == head) {
                head = nodeToDelete->next;
            }

            delete nodeToDelete; // Free memory
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Value " << targetValue << " not found in the list." << endl;
}
    // Display
    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;

        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        while (temp != head);

        cout << "HEAD" << endl;
    }
};

int main()
{
    CircularList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    cout << "Circular Linked List:" << endl;
    list.display();

    list.insertAtBeginning(5);

    cout << "\nAfter insertion at beginning:" << endl;
    list.display();
   
    list.insertAfter(30,100);
   
    cout<<"\nInserting after the position 30: "<<endl;
    list.display();
   
    list.deleteFromBeginning();
   
    cout<<"\nDeletion from beginning:"<<endl;
    list.display();
   
    list.deleteFromEnd();
   
     cout<<"\nDeletion from End:"<<endl;
    list.display();
   
     
    list.deleteAfter(20);

    cout << "\nAfter deleting node after 20:" << endl;
    list.display();
   
   
   
    return 0;
}
// Practical - 8 : Develop a program to construct a Binary Search Tree and demonstrate inorder , preorder and postorder traversals. 

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree
{
public:
    Node *root;

    BinaryTree()
    {
        root = nullptr;
    }

    Node* insert(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }

        if (value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insert(node->right, value);
        }
        else
        {
            cout << "Duplicate value " << value
                 << " is not inserted." << endl;
        }

        return node;
    }

    void display(Node *node, int space = 0)
    {
        if (node == nullptr)
        {
            return;
        }

        space += 5;

        display(node->right, space);

        cout << endl;

        for (int i = 5; i < space; i++)
        {
            cout << " ";
        }

        cout << node->data << endl;

        display(node->left, space);
    }

    void inorder(Node *node)
    {
        if (node == nullptr)
            return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node *node)
    {
        if (node == nullptr)
            return;

        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node *node)
    {
        if (node == nullptr)
            return;

        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    Node* findMin(Node *node)
    {
        while (node != nullptr && node->left != nullptr)
        {
            node = node->left;
        }

        return node;
    }

    Node* deleteNode(Node *node, int key)
    {
        if (node == nullptr)
        {
            return node;
        }

        if (key < node->data)
        {
            node->left = deleteNode(node->left, key);
        }
        else if (key > node->data)
        {
            node->right = deleteNode(node->right, key);
        }
        else
        {
            // Case 1: No child
            if (node->left == nullptr &&
                node->right == nullptr)
            {
                delete node;
                return nullptr;
            }

            // Case 2: Only right child
            else if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }

            // Case 2: Only left child
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }

            // Case 3: Two children
            else
            {
                Node *temp = findMin(node->right);

                node->data = temp->data;

                node->right =
                    deleteNode(node->right, temp->data);
            }
        }

        return node;
    }
};

int main()
{
    BinaryTree tree;

    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 70);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 60);
    tree.root = tree.insert(tree.root, 80);

    cout << "Binary Search Tree:" << endl;
    tree.display(tree.root);

    cout << "\nInorder Traversal: ";
    tree.inorder(tree.root);

    cout << "\nPreorder Traversal: ";
    tree.preorder(tree.root);

    cout << "\nPostorder Traversal: ";
    tree.postorder(tree.root);

    cout << "\n\nDeleting node 20..." << endl;
    tree.root = tree.deleteNode(tree.root, 20);

    cout << "\nBST after deletion:" << endl;
    tree.display(tree.root);

    cout << "\nInorder Traversal after deletion: ";
    tree.inorder(tree.root);

    cout << endl;

    return 0;
}
// Tree - Hierarchical Data Structure

// Traversal - BFS and DFS

// DFS - Inorder, Preorder and Postorder

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};

// Preorder - root, left, right
void preorder(Node *current)
{
    if (current == nullptr)
        return;

    cout << current->data << " ";
    preorder(current->left);
    preorder(current->right);
}

// Inorder - left, root, right
void inorder(Node *current)
{
    if (current == nullptr)
        return;

    inorder(current->left);
    cout << current->data << " ";
    inorder(current->right);
}

// Postorder - left, right, root
void postorder(Node *current)
{
    if (current == nullptr)
        return;

    postorder(current->left);
    postorder(current->right);
    cout << current->data << " ";
}

int main(void)
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);

    return 0;
}
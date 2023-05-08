#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

/*
Balanced Binary Tree
For every node -> abs(height(left) - height(right)) <= 1
*/
int height(Node *root);

bool isBalanced(Node *root)
{
    return height(root) != -1;
}

int height(Node *root)
{
    if (root == nullptr)
        return 0;

    int leftHeight = height(root->left);
    if (leftHeight == -1)
        return -1;
    int rightHeight = height(root->right);
    if (rightHeight == -1)
        return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1;

    return max(leftHeight, rightHeight) + 1;
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
    root->right->right->right->right = new Node(13);

    cout << isBalanced(root);
    return 0;
}
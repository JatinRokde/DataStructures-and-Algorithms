// Tree - Hierarchical Data Structure

// Traversal - BFS and DFS

// DFS - Inorder, Preorder and Postorder

#include <iostream>
#include <vector>
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
void preOrder(Node *current, vector<int> &preOrderTrav)
{
    if (current == nullptr)
        return;

    preOrderTrav.push_back(current->data);
    preOrder(current->left, preOrderTrav);
    preOrder(current->right, preOrderTrav);
}

// Inorder - left, root, right
void inOrder(Node *current, vector<int> &inOrderTrav)
{
    if (current == nullptr)
        return;

    inOrder(current->left, inOrderTrav);
    inOrderTrav.push_back(current->data);
    inOrder(current->right, inOrderTrav);
}

// Postorder - left, right, root
void postOrder(Node *current, vector<int> &postOrderTrav)
{
    if (current == nullptr)
        return;

    postOrder(current->left, postOrderTrav);
    postOrder(current->right, postOrderTrav);
    postOrderTrav.push_back(current->data);
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

    vector<int> preOrderTrav;
    preOrder(root, preOrderTrav);
    for (auto it : preOrderTrav)
    {
        cout << it << " ";
    }

    cout << endl;

    vector<int> inOrderTrav; 
    inOrder(root, inOrderTrav);
    for (auto it : inOrderTrav)
    {
        cout << it << " ";
    }
    cout << endl;
    
    vector<int> postOrderTrav;
    postOrder(root, postOrderTrav);
    for(auto it : postOrderTrav)
    {
        cout << it << " ";
    }

    return 0;
}
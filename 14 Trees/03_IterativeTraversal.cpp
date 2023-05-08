#include <iostream>
#include <vector>
#include <stack>
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
/*
Pseudo code

while(node != nullptr or !st.empty())
{
    if (node != nullptr)
    {
        print(node)
        st.push(node)
        node = node->left
    }
    else
    {
        node = st.pop()
        node = node->right
    }
}
*/
vector<int> preOrder(Node *root)
{
    vector<int> preOrderTrav;

    if (root == nullptr)
        return preOrderTrav;

    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        root = st.top();
        st.pop();
        preOrderTrav.push_back(root->data);

        // right pushed first so that the left be on the top of the stack
        if (root->right != nullptr)
            st.push(root->right);

        if (root->left != nullptr)
            st.push(root->left);
    }
    return preOrderTrav;
}
// Time complexity: O(n)
// Space complexity: O(n) = O(height)

// Inorder - left, root, right
/*
Pseudo code

while (node != nullptr or !st.empty())
{
    if (node != nullptr)
    {
        st.push(node)
        node = node->left
    }
    else
    {
        node = st.pop()
        print(node)
        node = node->right
    }
}
*/
vector<int> inOrder(Node *root)
{
    vector<int> inOrderTrav;

    stack<Node *> st;
    Node *node = root;

    while (true)
    {
        if (node != nullptr)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty())
                break;

            node = st.top();
            st.pop();
            inOrderTrav.push_back(node->data);
            node = node->right;
        }
    }
    return inOrderTrav;
}

// Postorder - left, right, root
/*
Pseudo code

while (node != nullptr or !st.empty())
{
    if (node != nullptr)
    {
        st.push(node)
        node = node->left
    }
    else
    {
        temp = st.pop()
        if (temp > 0)
        {
            st.push(-temp)
            node = temp->right
        }
        else
        {
            print(temp)
            node = nullptr
        }
    }
}
*/
vector<int> postOrder2Stack(Node *root)
{
    vector<int> postOrderTrav;

    if (root == nullptr)
        return postOrderTrav;

    stack<Node *> st1, st2;

    st1.push(root);
    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);

        if (root->left != nullptr)
            st1.push(root->left);

        if (root->right != nullptr)
            st1.push(root->right);
    }
    while (!st2.empty())
    {
        postOrderTrav.push_back(st2.top()->data);
        st2.pop();
    }
    return postOrderTrav;
}
// Time complexity: O(n)
// Space complexity: O(2n)

vector<int> postOrder1Stack(Node *cur)
{

    vector<int> postOrderTrav;
    if (cur == NULL)
        return postOrderTrav;

    stack<Node *> st;
    while (cur != NULL || !st.empty())
    {

        if (cur != NULL)
        {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            Node *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                postOrderTrav.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postOrderTrav.push_back(temp->data);
                }
            }
            else
                cur = temp;
        }
    }
    return postOrderTrav;
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
    preOrderTrav = preOrder(root);
    for (auto x : preOrderTrav)
    {
        cout << x << " ";
    }

    cout << endl;

    vector<int> inOrderTrav;
    inOrderTrav = inOrder(root);
    for (auto x : inOrderTrav)
    {
        cout << x << " ";
    }

    cout << endl;

    vector<int> postOrderTrav;
    postOrderTrav = postOrder2Stack(root);
    for (auto x : postOrderTrav)
    {
        cout << x << " ";
    }

    cout << endl;

    postOrderTrav = postOrder1Stack(root);
    for (auto x : postOrderTrav)
    {
        cout << x << " ";
    }
    return 0;
}
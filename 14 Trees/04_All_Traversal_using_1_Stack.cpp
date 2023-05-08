#include <iostream>
#include <stack>
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

/*
Pseudo Code

if (num == 1)
    preorder
    ++
    left

if (num == 2)
    inorder
    ++
    right

if (num == 3)
    postorder
*/
void treeTraversal(Node *root)
{
    stack<pair<Node *, int>> st;
    vector<int> preOrder, inOrder, postOrder;

    st.push({root, 1});

    if (root == nullptr)
        return;

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        if (it.second == 1)
        {
            preOrder.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right != nullptr)
            {
                st.push({it.first->left, 1});
            }
        }

        else if (it.second == 2)
        {
            inOrder.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right != nullptr)
            {
                st.push({it.first->right, 1});
            }
        }

        else
        {
            postOrder.push_back(it.first->data);
        }
    }

    for (auto it : preOrder)
    {
        cout << it << " ";
    }
    cout << endl;

    for (auto it : inOrder)
    {
        cout << it << " ";
    }
    cout << endl;

    for (auto it : postOrder)
    {
        cout << it << " ";
    }
}
// Time complexity: O(3n)
// Space complexity: O(4n)

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

    treeTraversal(root);

    return 0;
}
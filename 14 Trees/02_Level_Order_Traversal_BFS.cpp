#include <iostream>
#include <vector>
#include <queue>
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

vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> ans;

    if (root == nullptr)
        return ans;

    queue<Node *> q;

    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();

            if(node->left != nullptr)
            q.push(node->left);
            if(node->right != nullptr)
            q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
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

    vector<vector<int>> ans;
    ans = levelOrder(root);
    for(int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
    }
    return 0;
}
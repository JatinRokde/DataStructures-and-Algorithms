#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

void display(Node *head_ref)
{
    Node *current = head_ref;
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
}

void recursiveDisplay(Node *node)
{
    if (node)
    {
        cout << node->data << " ";
        recursiveDisplay(node->next);
    }
}

int countNodes(Node *node)
{
    int count = 0;
    while (node)
    {
        count++;
        node = node->next;
    }
    return count;
}

void insertAtHead(Node **head_ref, int value)
{
    Node *new_node = new Node(value);
    Node *current = *head_ref;

    if (current == nullptr)
    {
        *head_ref = new_node;
        return;
    }

    new_node->next = *head_ref;
    (*head_ref)->prev = new_node;
    *head_ref = new_node;
}

int main(void)
{
    Node *new_node = new Node(8);
    Node *head = new_node;
    recursiveDisplay(head);
    // cout << countNodes(head);

    insertAtHead(&head, 5);
    cout << endl;
    recursiveDisplay(head);
    return 0;
}
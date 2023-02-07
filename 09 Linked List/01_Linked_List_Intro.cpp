#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
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

void freeList(Node **head_ref)
{
    Node *current = *head_ref;
    Node *next = nullptr;

    while (current)
    {
        next = current->next;
        delete current;
        current = next;
    }
    (*head_ref) = nullptr;
}

int main(void)
{
    Node *new_node = new Node(10);
    Node *head = new_node;

    display(head);
    display(head);
    freeList(&head);
    display(head);
}
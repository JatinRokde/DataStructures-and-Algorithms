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

void insertAtEnd(Node **head_ref, int value)
{
    Node *new_node = new Node(value);
    Node *current = *head_ref;

    if (current == nullptr)
    {
        *head_ref = new_node;
        return;
    }

    while (current->next)
        current = current->next;

    current->next = new_node;
    new_node->prev = current;
}

void insertAnywhere(Node **head_ref, int index, int value)
{
    Node *new_node = new Node(value);
    Node *current = *head_ref;

    int count = countNodes(*head_ref);

    if (index < 1 or index > (count + 1))
        return;

    if (index == 1)
    {
        insertAtHead(head_ref, value);
        return;
    }

    if (index == (count + 1))
    {
        insertAtEnd(head_ref, value);
        return;
    }

    for (int i = 1; i < (index - 1); i++)
    {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    new_node->next->prev = new_node;
    new_node->prev = current;
}

int deleteHead(Node **head_ref)
{
    Node *temp = *head_ref;
    int x = -1;
    if (*head_ref == nullptr)
        return x;
    x = temp->data;
    (*head_ref) = (*head_ref)->next;
    (*head_ref)->prev = nullptr;
    delete temp;
    return x;
}

int deleteEnd(Node **head_ref)
{
    Node *current = *head_ref;
    Node *temp = nullptr;
    int x = -1;

    if (*head_ref == nullptr)
        return x;

    while (current->next)
    {
        current = current->next;
    }
    x = current->data;
    current->prev->next = nullptr;
    delete current;
    return x;
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

    insertAtEnd(&head, 12);
    cout << endl;
    display(head);

    insertAnywhere(&head, 2, 34);
    cout << endl;
    display(head);

    insertAnywhere(&head, 1, 10);
    cout << endl;
    display(head);

    insertAnywhere(&head, 6, 11);
    cout << endl;
    display(head);

    insertAnywhere(&head, 5, 45);
    cout << endl;
    display(head);

    deleteEnd(&head);
    cout << endl;
    display(head);
    return 0;
}
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
        this->next = nullptr;
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

    if (*head_ref == nullptr)
        *head_ref = new_node;

    new_node->next = *head_ref;
    (*head_ref) = new_node;
}

void insertAtEnd(Node **head_ref, int value)
{
    Node *new_node = new Node(value);
    Node *current = *head_ref;

    if (current == nullptr)
        *head_ref = new_node;

    while (current->next)
        current = current->next;

    current->next = new_node;
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
}

int sumElements(Node *head_ref)
{
    Node *current = head_ref;
    int sum = 0;

    while (current)
    {
        sum += current->data;
        current = current->next;
    }
    return sum;
}

int maxElement(Node *head_ref)
{
    Node *current = head_ref;
    int max = INT_MIN;
    while (current)
    {
        if (current->data > max)
            max = current->data;
        current = current->next;
    }
    return max;
}

int minElement(Node *head_ref)
{
    Node *current = head_ref;
    int min = INT_MAX;

    while (current)
    {
        if (current->data < min)
            min = current->data;
        current = current->next;
    }
    return min;
}

Node *search(Node *head_ref, int key)
{
    Node *current = head_ref;
    while (current)
    {
        if (key == current->data)
            return current;
        current = current->next;
    }
    return nullptr;
}

Node *recursiveSearch(Node *node, int key)
{
    if (node == nullptr)
        return nullptr;
    if (key == node->data)
        return node;
    return recursiveSearch(node->next, key);
}

// Improvising Linear Search - Move to Head
Node *improvisedLinearSearch(Node **head_ref, int key)
{
    Node *current = *head_ref;
    Node *follow = nullptr;

    while (current)
    {
        if (key == current->data)
        {
            follow->next = current->next;
            current->next = (*head_ref);
            (*head_ref) = current;
            return current;
        }
        follow = current;
        current = current->next;
    }
    return nullptr;
}

void sortedInsert(Node **head_ref, int value)
{
    Node *current = (*head_ref);
    Node *follow = nullptr;
    Node *new_node = new Node(value);

    if (current == nullptr)
    {
        (*head_ref) = new_node;
        return;
    }
    while (current and current->data < value)
    {
        follow = current;
        current = current->next;
    }

    new_node->next = follow->next;
    follow->next = new_node;
}

bool isSorted(Node *node)
{
    int x = INT_MIN;
    while (node)
    {
        if (node->data < x)
            return false;
        x = node->data;
        node = node->next;
    }
    return true;
}

int deleteHead(Node **head_ref)
{
    Node *temp = *head_ref;
    int x = -1;
    if (*head_ref == nullptr)
        return x;
    x = temp->data;
    (*head_ref) = (*head_ref)->next;
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
        temp = current;
        current = current->next;
    }
    temp->next = nullptr;
    x = current->data;
    delete current;
    return x;
}

int deleteAnywhere(Node **head_ref, int index)
{
    Node *current = *head_ref;
    Node *temp = nullptr;
    int x = -1;

    if (index < 1 or index > (countNodes(*head_ref) + 1))
        return x;

    for (int i = 0; i < (index - 1); i++)
    {
        temp = current;
        current = current->next;
    } 
    x = current->data;
    temp->next = current->next;
    delete current;
    return x;
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
    Node *new_node = new Node(5);
    Node *head = new_node;

    insertAtEnd(&head, 8);
    insertAtEnd(&head, 12);

    display(head);
    cout << endl;

    insertAtHead(&head, 3);
    display(head);

    cout << endl;

    // cout << countNodes(head);
    insertAnywhere(&head, 2, 4);

    recursiveDisplay(head);
    cout << endl;
    // cout << sumElements(head);
    // cout << maxElement(head);
    // cout << minElement(head);

    // Node *result = search(head, 22);
    // Node *result = recursiveSearch(head, 11);
    // Node *result = improvisedLinearSearch(&head, 12);

    // sortedInsert(&head, 6);

    // deleteHead(&head);
    // deleteEnd(&head);
    deleteAnywhere(&head, 2);
    display(head);
    // cout << endl;
    // cout << isSorted(head);
    freeList(&head);
    return 0;
}
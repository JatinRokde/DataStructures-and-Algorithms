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

    insertAtEnd(&head, 3);
    insertAtEnd(&head, 7);

    display(head);
    cout << endl;

    insertAtHead(&head, 11);
    display(head);

    cout << endl;

    // cout << countNodes(head);
    insertAnywhere(&head, 2, 12);

    

    recursiveDisplay(head);
    cout << endl;
    // cout << sumElements(head);
    // cout << maxElement(head);
    // cout << minElement(head);

    // Node *result = search(head, 22);
    // Node *result = recursiveSearch(head, 11);
    Node *result = improvisedLinearSearch(&head, 12);

    cout << result->data;
    cout << endl;
    display(head);
    freeList(&head);
    return 0;
}
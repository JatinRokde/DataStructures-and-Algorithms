#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void push(Node **top, int x)
{
    Node *temp;
    temp = new Node();
    if (temp == nullptr)
        cout << "Stack Overflow";
    else
    {

        temp->data = x;
        temp->next = *top;
        *top = temp;
    }
}

int pop(Node **top)
{
    Node *temp;
    int x = -1;

    if (top == nullptr)
        cout << "Stack Underflow";
    else
    {

        temp = *top;
        *top = (*top)->next;
        x = temp->data;
        free(temp);
    }
    return x;
}

void display(Node *top)
{
    Node *current = top;
    while (current)
    {
        cout << current->data;
        current = current->next;
    }
}

int main(void)
{
    Node *top = NULL;
    return 0;
}
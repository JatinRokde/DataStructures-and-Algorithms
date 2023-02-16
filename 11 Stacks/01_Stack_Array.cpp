#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *s;
};

void create(Stack *st)
{
    cout << "Enter Size: ";
    cin >> st->size;
    st->top = -1;
    st->s = new int[st->size];
}

void display(Stack st)
{
    for (int i = st.top; i >= 0; i--)
    {
        cout << st.s[i] << " ";
    }
}

void push(Stack *st, int x)
{
    if (st->top == st->size - 1)
    {
        cout << "Stack Overflow";
    }
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(Stack *st)
{
    int x = -1;
    if (st->top == -1)
        cout << "Stack Underflow";
    else
        x = st->s[st->top--];
    return x;
}

int peek(Stack st, int index)
{
    int x = -1;
    if (st.top - index + 1 < 0)
        cout << "Invalid Index";

    x = st.s[st.top - index + 1];
    return x;
}

bool isEmpty(Stack st)
{
    if (st.top == -1)
        return true;
    return false;
}

bool isFull(Stack st)
{
    if (st.top == st.size - 1)
        return true;
    return false;
}

int stackTop(Stack st)
{
    if (!isEmpty(st))
        return st.s[st.top];
    return -1;
}

int main(void)
{
    Stack st;
    create(&st);
    push(&st, 10);
    push(&st, 20);
    push(&st, 15);
    push(&st, 40);

    display(st);
    return 0;
}
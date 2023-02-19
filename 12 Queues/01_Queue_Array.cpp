#include <iostream>
using namespace std;

struct Queue
{
    int size;
    int front, rear;
    int *Q;
};

void create(Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = new int[q->size];
    // q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(Queue *q, int x)
{
    if (q->rear == q->size - 1)
    {
        cout << "Queue Overflow";
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
    {
        cout << "Queue Underflow";
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void display(Queue q)
{
    for (int i = q.front + 1; i <= q.rear; i++)
    {
        cout << q.Q[i] << " ";
    }
}

int main(void)
{
    Queue q;
    create(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 23);
    enqueue(&q, 21);
    display(q);
    dequeue(&q);
    cout << endl;
    display(q);
    return 0;
}
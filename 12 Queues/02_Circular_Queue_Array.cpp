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
    q->front = q->rear = 0;
    q->Q = new int[q->size];
}

void enqueue(Queue *q, int x)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        cout << "Queue Overflow";
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
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
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

void display(Queue q)
{
    int i = q.front + 1;
    do
    {
        cout << q.Q[i] << " ";
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);
}

int main(void)
{
    Queue q;
    create(&q, 6);
    enqueue(&q, 7);
    enqueue(&q, 11);
    enqueue(&q, 2);
    display(q);
    dequeue(&q);
    cout << endl;
    display(q);
    

    return 0;
}
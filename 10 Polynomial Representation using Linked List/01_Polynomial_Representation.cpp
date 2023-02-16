#include <iostream>
#include <math.h>
using namespace std;

struct Node
{
    int coeff;
    int exp;
    Node *next;
};

void create(Node **poly)
{
    Node *t, *last = nullptr;
    int num, i;
    cout << "Enter number of terms: ";
    cin >> num;

    cout << "Enter each term with coefficient and exponent:\n";
    for (i = 0; i < num; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        cin >> t->coeff >> t->exp;
        t->next = nullptr;

        if (*poly == nullptr)
        {
            *poly = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
}

void display(Node *poly)
{
    while (poly)
    {
        cout << poly->coeff << " x " << poly->exp << " + ";
        poly = poly->next;
    }
}

long evaluate(Node *poly, int x)
{
    long value = 0;
    while (poly)
    {
        value += poly->coeff * pow(x, poly->exp);
        poly = poly->next;
    }
    return value;
}

int main(void)
{
    Node *poly = nullptr;
    create(&poly);
    display(poly);
    cout << endl
         << evaluate(poly, 3);

    return 0;
}
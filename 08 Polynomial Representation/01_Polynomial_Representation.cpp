#include <iostream>
using namespace std;

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    struct Term *t;
};

void create(struct Poly *p)
{
    cout << "Number of terms?\n";
    cin >> p->n;
    p->t = (struct Term *)malloc(p->n * sizeof(struct Term));

    cout << "Enter terms:\n";
    for (int i = 0; i < p->n; i++)
    {
        cin >> p->t[i].coeff >> p->t[i].exp;
    }
}

void display(struct Poly p)
{
    for (int i = 0; i < p.n; i++)
    {
        cout << p.t[i].coeff << p.t[i].exp;
    }
}

struct Poly *add(struct Poly *p1, struct Poly *p2)
{
    int i, j, k;
    struct Poly *sum;
    sum = (struct Poly *)malloc(sizeof(struct Poly));
    sum->t = (struct Term *)malloc((p1->n + p2->n) * sizeof(struct Term));

    i = j = k = 0;
    while (i < p1->n and j < p2->n)
    {
        if (p1->t[i].exp > p2->t[j].exp)
        {
            sum->t[k++] = p1->t[i++];
        }
        else if (p1->t[i].exp < p2->t[j].exp)
        {
            sum->t[k++] = p2->t[j++];
        }
        else
        {
            sum->t[k].exp = p1->t[i].exp;
            sum->t[k++].coeff = p1->t[i++].coeff + p2->t[j++].coeff;
        }
    }

    for (; i < p1->n; i++)
    {
        sum->t[k++] = p1->t[i];
    }
    for (; j < p2->n; j++)
    {
        sum->t[k++] = p2->t[j];
    }
    sum->n = k;
    return sum;
}

int main(void)
{
    struct Poly p1, p2, *p3;
    create(&p1);
    create(&p2);

    // p3 = add(&p1, &p2);
    // cout << p1 << endl
    //      << p2 << endl;
    // cout << *p3;

    display(p1);
    cout << endl;
    display(p2);
    cout << endl;
    display(*p3);

    return 0;
}
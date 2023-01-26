#include <iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

void initialize(Rectangle *r, int l, int b)
{
    r->length = l;
    r->breadth = b;
}

int area(Rectangle r)
{
    return r.length * r.breadth;
}

void changeLength(Rectangle *r, int l)
{
    r->length = l;
}

int main(void)
{
    Rectangle r;
    initialize(&r, 10, 5);
    cout << area(r);
    changeLength(&r, 15);
    cout << endl
         << area(r);
    return 0;
}
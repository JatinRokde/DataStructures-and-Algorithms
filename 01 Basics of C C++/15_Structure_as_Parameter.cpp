#include <iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

// Call by value
int area(Rectangle r1)
{
    return r1.length * r1.breadth;
}

// Call by Address
void changeLength(Rectangle *p, int l)
{
    p->length = l;
}

int main(void)
{
    Rectangle r = {10, 5};
    cout << "Area: " << area(r);

    changeLength(&r, 15);
    cout << "\nNew Area: " << area(r);
    return 0;
}
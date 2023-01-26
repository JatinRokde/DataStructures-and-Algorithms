#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;

public:
    // Constructors
    Rectangle();
    Rectangle(int l, int b);

    // Facilitators
    int area();
    int perimeter();

    // Accessor
    int getLength();

    // Mutator
    void setLength(int l);

    // Destructor
    ~Rectangle();
};

Rectangle ::Rectangle()
{
    length = breadth = 1;
}

Rectangle ::Rectangle(int l, int b)
{
    length = l;
    breadth = b;
}

int Rectangle ::area()
{
    return length * breadth;
}

int Rectangle ::perimeter()
{
    return 2 * (length + breadth);
}

int Rectangle ::getLength()
{
    return length;
}

void Rectangle ::setLength(int l)
{
    length = l;
}

Rectangle ::~Rectangle()
{
    cout << "\nDestructor Invoked!";
}

int main(void)
{
    Rectangle r = {10, 5};

    cout << "Area: " << r.area();
    cout << endl
         << "Perimeter: " << r.perimeter();

    r.setLength(15);
    cout << endl
         << "Changed Length: " << r.getLength();

    cout << endl
         << "New Area: " << r.area() << endl
         << "New Perimeter: " << r.perimeter();
    return 0;
}
#include <iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main(void)
{
    Rectangle r = {10, 5};
    Rectangle *p = &r;

    cout << "Length: " << r.length;  
    cout << "\nBreadth: " << r.breadth;

    cout << endl;

    cout << "\nLength: " << (*p).length; // p->length
    cout << "\nBreadth: " << p->breadth;

    p->length = 15;
    cout << "\n\nNew Length: " << p->length;

    delete p;  
    return 0;
}
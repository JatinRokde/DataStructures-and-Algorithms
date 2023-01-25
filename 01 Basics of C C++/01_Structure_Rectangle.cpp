#include <iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main(void)
{
    Rectangle r = {10, 5}; // declaration and initialization

    cout << "Length: " << r.length;
    cout << "\nBreadth: " << r.breadth; 

    cout << "\nArea: " << r.length * r.breadth;
    return 0;
}
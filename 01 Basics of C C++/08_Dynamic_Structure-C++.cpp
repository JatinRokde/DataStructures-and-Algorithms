#include <iostream>
using namespace std;

struct Rectangle 
{
    int length;
    int breadth;
};

int main()
{
    Rectangle *p;
    p = new Rectangle;

    p->length = 10;
    p->breadth = 5;

    cout <<"Length: " << p->length;
    cout <<"\nBreadth: " << p->breadth;

    delete p;      
    return 0;
}
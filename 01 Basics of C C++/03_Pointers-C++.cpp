#include <iostream>
using namespace std;

int main(void)
{
    int a = 10;
    int *p;
    p = &a;

    cout << a << endl; // 10 
    cout << p << endl;  // address of a
    cout << &a << endl;  // address of a
    cout << &p << endl; // address of p
    cout << *p << endl; // value of p (= a) = 10

    delete p;
    return 0;
}
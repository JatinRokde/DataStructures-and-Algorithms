// Reference:- Alias given to a variable.

#include <iostream>
using namespace std;

int main(void)
{
    int a = 10;
    int &r = a;

    cout << a; // 10
    cout << endl << r; // 10

    r++;

    cout << endl << a ; // 11
    cout << endl << r; // 11

    int b = 25;
    r = b;

    cout << endl << a; // 25
    cout << endl << r; // 25

    // Reference cannot be changed once initialized
    
    return 0;
}
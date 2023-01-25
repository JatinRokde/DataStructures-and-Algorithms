#include <iostream>
using namespace std;

// In this, the changes made to the formal parameters, affects the actual parameters.
void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a, b;
    a = 10, b = 5;

    cout << "The values of a and b before swapping:\n";
    cout << a << " " << b;

    swap(a, b);
    cout << "\n\nThe values of a and be after swapping:\n";
    cout << a << " " << b;
    return 0;
}
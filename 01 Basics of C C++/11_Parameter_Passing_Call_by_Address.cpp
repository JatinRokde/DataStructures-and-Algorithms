#include <iostream>
using namespace std;

// In this, any changes made to the formal parameters also affect the actual parameters.
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(void)
{
    int a, b;
    a = 10, b = 5;

    cout << "The values of a and b before swapping is:\n";
    cout << a << " " << b;

    swap(&a, &b);
    cout << "\n\nThe values of a and b after swapping is:\n";
    cout << a << " " << b;
    return 0;
}
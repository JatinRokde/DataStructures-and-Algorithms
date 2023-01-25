#include <iostream>
using namespace std;

int add(int a, int b)
{
    int c = a + b;
    return c;
}

int main(void)
{
    int x, y, z;
    x = 10;
    y = 5;
    z = add(x, y);

    cout << z;
    return 0;
}
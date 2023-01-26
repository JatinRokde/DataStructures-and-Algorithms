#include <iostream>
using namespace std;

// If a function A calls another function B, and the function B calls back the function A again, either directly or indirectly, then it is called as Indirect Recursion.

void funB(int n);

void funA(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        funB(n - 1);
    }
}

void funB(int n)
{
    if (n > 1)
    {
        cout << n << " ";
        funA(n / 2);
    }
}

int main(void)
{
    funA(10);
    return 0;
}
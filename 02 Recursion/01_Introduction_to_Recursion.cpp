#include <iostream>
using namespace std;

// A function calling itself is known as Recursive function and this concept is known as Recursion.

void fun1(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        fun1(n - 1);
    }
}

void fun2(int n)
{
    if (n > 0)
    {
        fun2(n - 1);
        cout << n << " ";
    }
}

int main(void)
{
    int x = 5;
    cout << "fun1() being called: ";
    fun1(x);

    cout << "\nfun2() being called: ";
    fun2(x);
    return 0;
}
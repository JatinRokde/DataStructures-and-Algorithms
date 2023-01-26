#include <iostream>
using namespace std;

// If a function calls itself more than one time, then it is called as tree recursion, whereas if the recursive function is calling itself just once, then it is called as linear recursion.

void fun(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        fun(n - 1);
        fun(n - 1);
    }
}

int main(void)
{
    fun(5);
    return 0;
}
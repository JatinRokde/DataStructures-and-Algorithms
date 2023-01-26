#include <iostream>
using namespace std;

// Function call is the last thing done in the tail recursion. Function does not perform any operation at the returning time.

void fun1(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        fun1(n - 1);
    }
}

// Tail recursion can be easily modified into a loop.

int main(void)
{
    fun1(5);
    return 0;
}
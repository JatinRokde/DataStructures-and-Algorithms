#include <iostream>
using namespace std;

// In head recursion all of the processing is done during the function returning time. Function doesn't do anything at the calling time.

void fun(int n)
{
    if (n > 0)
    {
        fun(n - 1);
        cout << n << " ";
    }
}

// Head recursion cannot be easily modified into a loop.

int main(void)
{
    fun(5);
    return 0;
}
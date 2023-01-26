#include <iostream>
using namespace std;

// the fibonacci function is an example of an excessive recursion, to optimise the function, we can use the concept of memoization.
int F[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
int fibonacci(int n)
{
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 2] == -1)
        {
            F[n - 2] = fibonacci(n - 2);
        }
        if (F[n - 1] == -1)
        {
            F[n - 1] = fibonacci(n - 1);
        }
        F[n] = F[n - 1] + F[n - 2];
        return F[n - 1] + F[n - 2];
    }
}

int main(void)
{
    cout << fibonacci(6);
    return 0;
}
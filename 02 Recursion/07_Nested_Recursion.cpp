#include <iostream>
using namespace std;

// If in a recursive function, the recursive function is passing parameter as a recursive call, then it is called as nested recursion.

int fun(int n)
{
    if (n > 100)
    {
        return (n - 10);
    }
    else 
    {
        return fun(fun(n + 11));
    }
}

int main(void)
{
    cout << fun(97);
    return 0;
}
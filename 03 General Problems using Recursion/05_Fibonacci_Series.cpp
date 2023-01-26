#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 2) + fibonacci(n - 1);
}

// Using loop
int Ifibonacci(int n)
{
    int first = 0, second = 1, sum = 0;
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    for (int i = 1; i < n; i++)
    {
        sum = first + second;
        first = second;
        second = sum;
    }
    return sum;
}

int main(void)
{
    cout << fibonacci(5) << endl;
    cout << Ifibonacci(5);
    return 0;
}
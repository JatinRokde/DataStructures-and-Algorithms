#include <iostream>
using namespace std;

// Taylor Series: e^x = 1 + x + x/1! + x^2/2! + x^3/3! + ... n terms
double e(int x, int n)
{
    static int p = 1, f = 1;
    double r;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        r = e(x, n - 1);
        p = p * x;
        f = f * n;
        return (r + (double)p / f);
    }
} // Time complexity = O(n^2)

// Taylor Series using Horner's rule
double horner_e(int x, int n)
{
    static double s;
    if (n == 0)
    {
        return s;
    }
    s = 1 + x * s / n;
    return horner_e(x, n - 1);
} // Time complexity = O(n)

int main(void)
{
    cout << e(2, 9) << endl;
    cout << horner_e(2, 9);
    return 0;
}
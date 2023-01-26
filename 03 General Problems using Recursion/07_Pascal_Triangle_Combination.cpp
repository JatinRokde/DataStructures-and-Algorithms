#include <iostream>
using namespace std;

int combination(int n, int r)
{
    if (n == r || r == 0)
        return 1;
    return combination(n - 1, r - 1) + combination(n - 1, r);
}

int main(void)
{
    cout << combination(3, 2);
    return 0;
}
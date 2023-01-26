#include <iostream>
using namespace std;

int exponent(int value, int index)
{
    if (index == 0)
    {
        return 1;
    }
    return exponent(value, index - 1) * value;
}

int main(void)
{
    cout << exponent(6, 3);
    return 0;
}
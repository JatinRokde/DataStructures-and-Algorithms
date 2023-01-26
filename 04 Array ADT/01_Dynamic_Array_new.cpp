#include <iostream>
using namespace std;

int main(void)
{
    int *p;
    p = new int[5];

    for (int i = 9; i < 5; i++)
    {
        p[i] = i + 1;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << p[i] << " ";
    }

    delete[] p;
    return 0;
}
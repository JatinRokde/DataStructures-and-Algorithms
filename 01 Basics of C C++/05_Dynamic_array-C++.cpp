#include <iostream>
using namespace std;

int main(void)
{
    int *p;
    p = new int[3];

    p[0] = 4;
    p[1] = 6;
    p[2] = 5;

    for (int i = 0; i < 3; i++)
        cout << p[i] << " ";

    delete[] p;
    return 0;
}
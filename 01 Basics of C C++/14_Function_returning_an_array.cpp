#include <iostream>
using namespace std;

int *fun(int size)
{
    int *p;
    p = new int[5];
    // p = (int *)malloc(sizeof(int) * 5);

    for (int i = 0; i < size; i++)
    {
        p[i] = i + 1;
    }
    return p;
}

int main(void)
{
    int *ptr, size = 5;
    ptr = fun(size);

    for (int i = 0; i < size; i++)
    {
        cout << ptr[i] << " ";
    }
    return 0;
}
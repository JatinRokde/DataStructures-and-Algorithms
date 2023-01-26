#include <iostream>
using namespace std;

int main(void)
{
    int *p;
    p = (int *)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        p[i] = i + 1;
    }

    for(int i = 0; i < 5; i++)
    {
        cout << p[i] << " ";
    }

    free(p);
    return 0;
}
#include <iostream>
using namespace std;

int main(void)
{
    int A[5] = {2, 3, 4, 5, 6};
    int *p;
    p = A; // p = &A[0]

    for (int i = 0; i < 5; i++)
        cout << p[i] << " ";

    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << *(p + i) << " ";
    }
    return 0;
}
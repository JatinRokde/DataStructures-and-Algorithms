#include <iostream>
using namespace std;

int main(void)
{
    char A[] = "Programming";
    char B[11];
    int i, j;

    for (i = 0; A[i] != '\0'; i++)
    {
    }
    i = i - 1;
    for (j = 0; i >= 0; i--, j++)
    {
        B[j] = A[i];
    }
    B[j] = '\0';
    cout << B;
    return 0;
}
#include <iostream>
using namespace std;

// Arrays are always passed as pass by address method
void fun1(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    A[2] = 10;
}
// A[] is like an pointer to an array pointing to the first element of the array.

void fun2(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}

int main(void)
{
    int A[5] = {3, 5, 1, 7, 4};
    fun1(A, 5);
    cout << endl;

    fun2(A, 5);
    cout << endl;

    for (int i = 0; i < 5; i++)   
    {
        cout << A[i] << " ";
    }
    return 0;
}
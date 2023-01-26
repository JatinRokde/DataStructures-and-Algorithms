#include <iostream>
using namespace std;

int main(void)
{
    // Creating array Partially in heap and partially in stack
    int *A[3];
    A[0] = new int[5];
    A[1] = new int[5];
    A[2] = new int[5];

    A[1][4] = 6;
    cout << A[1][4] << endl;

    // free(A[0]);
    delete[] A[0];
    delete[] A[1];
    delete[] A[2];

    // Creating array completely in heap
    int **B;
    B = new int *[3];
    // B = (int **)malloc(3 * sizeof(int *));

    B[0] = new int[4];
    // B[0] = (int *)malloc(4 * sizeof(int));
    B[1] = new int[4];
    B[2] = new int[4];

    B[1][3] = 5;
    cout << B[1][3];

    delete[] B[0];
    delete[] B[1];
    delete[] B[2];
    delete[] B;
    // free(B[1]);
    return 0;
}
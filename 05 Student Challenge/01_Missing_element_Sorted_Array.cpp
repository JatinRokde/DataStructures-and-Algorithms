#include <iostream>
using namespace std;

// One element is Missing in an array beginning from 1
int missingElement_1(int A[], int size)
{
    int sum = 0, actual_sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += A[i];
    }
    int t = size + 1;
    actual_sum = (t * (t + 1)) / 2;

    return actual_sum - sum;
}

int main(void)
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int A[size];

    cout << "\nEnter Array Elements:\n";
    for (int i = 0; i < size; i++)
    {
        cin >> A[i];
    }

    cout << "Missing element: " << missingElement_1(A, size);

    return 0;
}
#include <iostream>
using namespace std;

// Duplicates in a Sorted Array
int main(void)
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int A[size];
    cout << "\nEnter Elements:\n";
    for (int i = 0; i < size; i++)
    {
        cin >> A[i];
    }

    int LastDuplicate = 0;
    for (int i = 0; i < size; i++)
    {
        if ((A[i] == A[i + 1]) && (A[i] != LastDuplicate))
        {
            LastDuplicate = A[i];
            cout << A[i] << " ";
        }
    }
    return 0;
}
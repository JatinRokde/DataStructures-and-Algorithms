#include <iostream>
using namespace std;

// When only one element is missing
void missingElement1(int A[], int size)
{
    int difference = A[0] - 0;
    for (int i = 0; i < size; i++)
    {
        if (A[i] - i != difference)
        {
            cout << i + difference;
            break;
        }
    }
}

// When more than one element is missing
void missingElement2(int A[], int size)
{
    int difference = A[0] - 0; // element - index

    for (int i = 0; i < size; i++)
    {
        if (A[i] - i != difference)
        {
            while (difference < A[i] - i)
            {
                cout << i + difference << " ";
                difference++;
            }
        }
    }
}


int main(void)
{
    int size;
    cout << "Enter size of the array: ";
    cin >> size;

    int A[size];

    cout << "\nEnter elements:\n";

    for (int i = 0; i < size; i++)
    {
        cin >> A[i];
    }

    missingElement2(A, size);
    return 0;
}
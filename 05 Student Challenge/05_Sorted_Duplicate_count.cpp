#include <iostream>
using namespace std;

int main(void)
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int A[size];
    cout << "\nEnter elements:\n";
    for (int i = 0; i < size; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < size; i++)
    {
        if (A[i] == A[i + 1])
        {
            int j = i + 1;
            while (A[j] == A[i])
            {
                j++;
            }
            cout << A[i] << " is appearing " << (j - i) << " times\n";
            i = j - 1;
        }
    }

    return 0;
}
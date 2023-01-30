#include <iostream>
using namespace std;

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

    int max = A[0];
    for (int i = 1; i < size; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }

    int H[max + 1] = {0};
    for (int i = 0; i < size; i++)
    {
        H[A[i]]++;
    }

    cout << "\nDuplicate elements are:\n";
    for (int i = 0; i < size; i++)
    {
        if (H[i] > 1)
        {
            cout << i << " " << H[i] << endl;
        }
    }
    return 0;
}
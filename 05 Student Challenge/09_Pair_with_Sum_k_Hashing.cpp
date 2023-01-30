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

    int k = 10;
    int max = A[0];
    for (int i = 0; i < size; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }

    int H[max + 1] = {0};
    for (int i = 0; i < size; i++)
    {
        H[A[i]] = 1;
    }

    for (int i = 0; i < size; i++)
    {
        if (H[k - A[i]] != 0)
        {
            cout << A[i] << " " << k - A[i] << endl;
        }
    }

    
    return 0;
}
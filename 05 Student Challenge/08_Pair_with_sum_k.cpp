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

    for (int i = 0; i < size -1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (A[i] + A[j] == k)
            {
                cout << A[i] << " " << A[j] << endl;
            }
        }
    }

    return 0;
}
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

    int min, max;
    min = max = A[0];

    for (int i = 0; i < size; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
        else if (A[i] > max)
        {
            max = A[i];
        }
    }

    cout << "Min = " << min << " Max = " << max;
    return 0;
}
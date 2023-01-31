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
    int i, j;
    i = 0;
    j = size - 1;

    while (i < j)
    {
        if (A[i] + A[j] == k)
        {
            cout << A[i] << " " << A[j] << endl;
            i++;
            j--;
        }
        else if (A[i] + A[j] < k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return 0;
}
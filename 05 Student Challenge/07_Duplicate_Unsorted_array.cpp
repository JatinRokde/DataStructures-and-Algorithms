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

    for (int i = 0; i < size - 1; i++)
    {
        int count = 1;
        if (A[i] != -1)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (A[i] == A[j])
                {
                    count++;
                    A[j] = -1;
                }
            }
            if (count > 1)
            {
                cout << A[i] << " " << count << endl;
            }
        }
    }

    return 0;
}
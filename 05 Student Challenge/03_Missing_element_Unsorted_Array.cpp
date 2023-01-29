#include <iostream>
using namespace std;

// Using the technique of Hashing
int main(void)
{
    int size;
    cout << "Enter size of the array:";
    cin >> size;

    int A[size];

    cout << "\nEnter elements:\n";
    for(int i = 0; i < size; i++)
    {
        cin >> A[i];
    }
    
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

    cout << "\nMissing Elements:\n";
    for (int i = 1; i < (max + 1); i++)
    {
        if (H[i] == 0)
        {
            cout << i << " ";
        }
    }
    return 0;
}
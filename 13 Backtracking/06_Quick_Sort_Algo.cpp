// Approach - Divide and Conquer - Find pivot

// Rules for deciding pivot
// First number
// Mid of the array
// Median of the array
// Any random number

// Find the pivot and place it in its correct position
// All elements lesser than pivot on its left and greater than pivot on its right

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot and i <= high - 1)
        {
            i++;
        }

        while (arr[j] > pivot and j >= low + 1)
        {
            j--;
        }

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

int main(void)
{
    vector<int> arr = {5, 2, 9, 1, 5, 6, 3};
    quickSort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
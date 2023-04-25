// Merge Sort - Divide and Merge

// Approach - Divide the array until each element acts as a separate array, Merge the array

#include <iostream>
using namespace std;

void merge(int arr[], int n, int low, int mid, int high)
{
}

void mergeSort(int arr[], int n, int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;

    mergeSort(arr, n, low, mid);
    mergeSort(arr, n, mid + 1, high);
    merge(arr, n, low, mid, high);
}

int main(void)
{
    int arr[] = {2, 1, 5, 3, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, n, 0, n - 1);
    return 0;
}
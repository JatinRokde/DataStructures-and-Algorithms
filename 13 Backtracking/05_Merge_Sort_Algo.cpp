// Merge Sort - Divide and Merge

// Approach - Divide the array until each element acts as a separate array, Merge the array

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    vector<int> temp;
    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= m)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= r)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for (int k = l; k <= r; k++)
    {
        arr[k] = temp[k - l];
    }
}

void mergeSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int n = arr.size();
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

// Count number of Subsequences

// Structure of the Code

// int func()
//     if (baseCondition Satisfies)
//         return 1
//     else return 0

//     (Call the left and right of the function independently)
//     left = func()
//     right = func()

//     (Return the sum of left and right)
//     return left + right

#include <iostream>
#include <vector>
using namespace std;

int subsequenceK(int index, int csum, int sum, int *arr, int n)
{
    // if array contains positives only, then
    if (csum > sum)
        return 0;

    if (index == n)
    {
        if (csum == sum)
        {
            return 1;
        }
        return 0;
    }

    // take the element
    csum += arr[index];
    int left = subsequenceK(index + 1, csum, sum, arr, n);

    // do not take the element
    csum -= arr[index];
    int right = subsequenceK(index + 1, csum, sum, arr, n);

    return left + right;
}
// Time Complexity = O(2^n);

int main(void)
{
    int arr[] = {1, 2, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 2;
    vector<int> ans;

    cout << subsequenceK(0, 0, sum, arr, n);   
    return 0;
}
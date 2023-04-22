// Print all the subsequences with sum = k

// Approach - Making all possible recursion calls and checking for the sum in each recursion call

#include <iostream>
#include <vector>
using namespace std;

void subsequenceK(int index, vector<int>& ans, int isum, int sum, int *arr, int n)
{
    if (index == n)
    {
        if (isum == sum)
        {
            for (auto it : ans)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }

    // take the element
    ans.push_back(arr[index]);
    isum += arr[index];
    subsequenceK(index + 1, ans, isum, sum, arr, n);

    // not take the element
    isum -= arr[index];
    ans.pop_back();
    subsequenceK(index + 1, ans, isum, sum, arr, n);
}

int main(void)
{
    int arr[] = {1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 2;
    vector<int> ans;

    subsequenceK(0, ans, 0, sum, arr, n);   
    return 0;
}
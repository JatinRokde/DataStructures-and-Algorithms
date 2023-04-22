// Printing any 1 subsequence whose sum = k;

// Structure of the Code

// func()
//     if (baseCondition statisfies)
//         return true;
//     else 
//         return false;

//      (make rest of the function calls)
//     if (func() == true);
//         return true;    

//     (if none of the function call satisfies the condition, return false)
//     return false


#include <iostream>
#include <vector>
using namespace std;

bool subsequenceK(int index, vector<int>& ans, int csum, int sum, int *arr, int n)
{
    if (index == n)
    {
        // if condition statisfies - return true
        if (csum == sum)
        {
            for (auto it : ans)
            {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        // else return false
        return false;
    }

    ans.push_back(arr[index]);
    csum += arr[index];
    if (subsequenceK(index + 1, ans, csum, sum, arr, n) == true)
    {
        return true;
    }

    csum -= arr[index];
    ans.pop_back();
    if(subsequenceK(index + 1, ans, csum, sum, arr, n) == true)
    {
        return true;
    }

    return false;
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
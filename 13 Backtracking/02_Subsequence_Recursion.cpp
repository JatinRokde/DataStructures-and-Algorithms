#include <iostream>
#include <vector>
using namespace std;

void subsequence(int index, vector<int> &ans, int *arr, int n)
{
    if (index == n)
    {
        if (ans.size() == 0)
        {
            cout << "{}"
                 << " ";
        }
        else
        {
            for (auto it : ans)
            {
                cout << it << " ";
            }
        }
        cout << endl;
        return;
    }

    // take the element
    ans.push_back(arr[index]);
    subsequence(index + 1, ans, arr, n);

    // do not take the element
    ans.pop_back();
    subsequence(index + 1, ans, arr, n);
}

int main(void)
{
    int arr[] = {3, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> ans;
    subsequence(0, ans, arr, n);
    return 0;
}
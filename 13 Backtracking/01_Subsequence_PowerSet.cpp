// Subsequence - A contiguous/non-contiguous sequence which follows the order.
// eg. arr = [3, 1, 2]
// All possible subsequence = {}, 3, 1, 2, 3 1, 1 2, 3 2, 3 1 2
// Total subsequences = 8

#include <iostream>
#include <vector>
using namespace std;

vector<string> allPossibleStrings(string s)
{
    int n = s.length();
    vector<string> ans;

    for (int num = 0; num < (1 << n); num++)
    {
        string sub = "";
        for (int i = 0; i < n; i++)
        {
            // Check for ith bit set or unset
            if (num & (1 << i))
            {
                sub += s[i];
            }
        }
        ans.push_back(sub);
    }
    return ans;
}
// Time Complexity : O((2^n) * n)

int main(void)
{
    string s="abc";
	vector<string>ans = allPossibleStrings(s);

	//printing all the subsequence.
	cout<<"All possible subsequences are "<<endl;
	for (auto it : ans) {
		cout << it << endl;
	}
    return 0;
}
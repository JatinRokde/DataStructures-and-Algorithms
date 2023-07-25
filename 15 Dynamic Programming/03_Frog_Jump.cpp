#include <iostream>
#include <vector>
using namespace std;

// Recursive approach
int frogJump(int n, vector<int> &heights, vector<int> &dp)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int oneJump = frogJump(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]);
    int twoJump = INT_MAX;
    if (n > 1)
    {
        twoJump = frogJump(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]);
    }
    return dp[n] = min(oneJump, twoJump);
}
// Time Complexity = O(n)
// Space Complexity = O(n) + O(n)

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    dp[0] = 0; // define the base case

    // begin the loop in the opposite order of recursion
    for (int i = 1; i < n; i++)
    {
        int oneJump = dp[i - 1] + abs(heights[i] - heights[i - 1]);

        int twoJump = INT_MAX;
        if (i > 1)
        {
            twoJump = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }
        dp[i] = min(oneJump, twoJump);
    }
    // the last index will store the final ans
    return dp[n - 1];
}
// Time Complexity = O(n)
// Space Complexity = O(n)

int main(void)
{
    vector<int> heights{10, 20, 30, 10};
    int n = heights.size();
    // vector<int> dp(n, -1);
    // cout << frogJump(n - 1, heights, dp);
    cout << frogJump(n, heights);

    return 0;
}
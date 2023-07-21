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

int main(void)
{
    vector<int> heights{10, 20, 30, 10};
    int n = heights.size();
    vector<int> dp(n, -1);
    cout << frogJump(n-1, heights, dp);

    return 0;
}
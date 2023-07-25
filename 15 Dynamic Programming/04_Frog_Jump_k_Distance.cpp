#include <iostream>
#include <vector>
using namespace std;

// DP - Recursive - Top down approach
int frogJump(int n, int k, vector<int> &heights, vector<int> &dp)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int minEnergy = INT_MAX;
    int jump;

    for (int j = 1; j <= k; j++)
    {
        if (n - j >= 0)
        {
            jump = frogJump(n - j, k, heights, dp) + abs(heights[n] - heights[n - j]);
        }
        minEnergy = min(minEnergy, jump);
    }
    return dp[n] = minEnergy;
}
// Time Complexity = O(n * k)
// Space Complexity = O(n) + O(n)

int main(void)
{
    vector<int> heights{10, 20, 30, 10};
    int n = heights.size();
    int k = 3;
    vector<int> dp(n, -1);
    cout << frogJump(n - 1, k, heights, dp);
    return 0;
}
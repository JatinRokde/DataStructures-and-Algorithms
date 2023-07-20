#include <iostream>
#include <vector>
using namespace std;

// 1D DP Problem
// Understand a DP
// - Count the total number of ways
// - Multiple possible ways, figure out the min/max or the best one

// Approach to solve
// Try to represent the problem in terms of index
// Do all possible stuffs on that index based on the problem statement
// - sum of all stuffs - count all ways
// - min/max of all stuffs - find min/max

// int stairsCount(int n, vector<int> &dp)
// {
//     if (n == 0 or n == 1)
//         return 1;

//     if (dp[n] != -1)
//         return dp[n];
//     int oneJump = stairsCount(n - 1, dp);
//     int twoJump = stairsCount(n - 2, dp);

//     return oneJump + twoJump;
// }

int stairsCount(int n, vector<int> &dp)
{
    if (n == 0 or n == 1)
        return 1;

    if (dp[n] != -1)
        return dp[n];
    return stairsCount(n - 1, dp) + stairsCount(n - 2, dp);
}
// Time Complexity = O(n)
// Space Complexity = O(n) + O(n)

int main(void)
{
    int n = 3;
    vector<int> dp(n + 1, -1);
    cout << stairsCount(3, dp);
    return 0;
}
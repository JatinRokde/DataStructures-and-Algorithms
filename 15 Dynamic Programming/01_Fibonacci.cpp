#include <iostream>
#include <vector>
using namespace std;

// DP - Top down - Recursive approach
// Memoization - to store the values of sub problems in some map/table
int fibonacci(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];
    return fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
}
// Time Complexity = O(n)
// Space Complexity = O(n) + O(n)

// DP - Tabulation - Bottom up approach
int fibonacci(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
// Time Complexity = O(n)
// Space Complexity = O(n) (No extra recursion stack space is used)

// DP - Tabulation with Space Optimisation
int fibonacci_(int n)
{
    int prev2 = 0, prev = 1;
    int curr = 0;

    for (int i = 2; i <= n; i++)
    {
        curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return curr;
}
// Time Complexity = O(n)
// Space Complexity = O(1)

int main(void)
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    // cout << fibonacci(n, dp);
    cout << fibonacci(n);
    return 0;
}
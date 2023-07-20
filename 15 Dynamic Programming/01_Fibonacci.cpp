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

int main(void)
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << fibonacci(n, dp);
    return 0;
}
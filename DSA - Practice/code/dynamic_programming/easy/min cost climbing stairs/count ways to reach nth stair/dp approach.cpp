#include <bits/stdc++.h>
#define MOD 1000000007

/*




*/

int solve(int n, vector<int> &dp)
{

    // check dp
    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = (solve(n - 1, dp) + solve(n - 2, dp)) % MOD;
    return dp[n];
}

int countDistinctWays(int n)
{
    //  Write your code here.

    int ans = 0;

    vector<int> dp(n + 1, -1);
    dp[0] = 1;
    dp[1] = 1;

    return solve(n, dp);
}
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

bool solve(int n, int target, int index, vector<int> &arr, vector<vector<int>> &dp)
{

    // base cases
    if (index < 0)
    {
        return false;
    }

    if (target == 0)
    {
        return true;
    }

    if (index == 0)
    {
        return arr[index] == target;
    }

    // check in dp
    if (dp[index][target] != -1)
    {
        return dp[index][target];
    }

    bool include = false;
    // include
    if (arr[index] <= target)
    {
        include = solve(n, target - arr[index], index - 1, arr, dp);
    }

    // exclude
    bool exclude = solve(n, target, index - 1, arr, dp);

    // populate dp
    return dp[index][target] = include || exclude;
}

bool subsetSumToK(int n, int target, vector<int> &arr)
{
    // Write your code here.

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1)); // Fix dimension initialization

    return solve(n, target, n - 1, arr, dp);
}

int main()
{

    return 0;
}
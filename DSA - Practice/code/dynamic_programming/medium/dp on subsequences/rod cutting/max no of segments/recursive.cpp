#include <bits/stdc++.h>

/*

https://www.codingninjas.com/studio/problems/cut-into-segments_1214651
https://www.youtube.com/watch?v=MFAAZW2znv8&list=PLDzeHZWIZsTomOPnCiU3J95WufjE36wsb&index=6


*/

// BASIC RECURSIVE SOLUTION - TLE
int solveRec(int n, int x, int y, int z)
{

    // base case
    if (n == 0)
    {
        return 0;
    }

    if (n < 0)
    {
        return INT_MIN;
    }

    // because we have fixed number of types of segments, which are x,y and z
    // so we try for each of them here
    // so first condition will be that we consider x first, then second will be that we consider

    int a = 1 + solveRec(n - x, x, y, z);
    int b = 1 + solveRec(n - y, x, y, z);
    int c = 1 + solveRec(n - z, x, y, z);

    return max(a, max(b, c));
}

// RECURSIVE SOLUTION WITH MEMOIZATION
int solveRecMem(int n, int x, int y, int z, vector<int> &dp)
{

    // base case
    if (n == 0)
    {
        return 0;
    }

    if (n < 0)
    {
        return INT_MIN;
    }

    // check in dp
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // because we have fixed number of types of segments, which are x,y and z
    // so we try for each of them here
    // so first condition will be that we consider x first, then second will be that we consider

    int a = 1 + solveRecMem(n - x, x, y, z, dp);
    int b = 1 + solveRecMem(n - y, x, y, z, dp);
    int c = 1 + solveRecMem(n - z, x, y, z, dp);

    return dp[n] = max(a, max(b, c));
}

// ALTERNATIVE method to solving recursively with memoization

int solveRecMem2(vector<int> &dp, vector<int> nums, int target, int index)
{

    // base cases
    if (index >= nums.size())
    {
        return INT_MIN;
    }

    if (target == 0)
    {
        return 0;
    }

    if (target < 0)
    {
        return INT_MIN;
    }

    // check in dp
    if (dp[target] != -1)
    {
        return dp[target];
    }

    // include or exclude

    int include = 1 + solveRecMem2(dp, nums, target - nums[index], index);

    int exclude = solveRecMem2(dp, nums, target, index + 1);

    // populate dp
    return dp[target] = max(include, exclude);
}

int cutSegments(int n, int x, int y, int z)
{
    // Write your code here.

    vector<int> dp(n + 1, -1);
    vector<int> nums;
    nums.push_back(x);
    nums.push_back(y);
    nums.push_back(z);

    int ans = INT_MIN;

    // basic recursive
    // ans = solveRec(n, x, y, z);

    // recursive memoization
    // ans = solveRecMem(n, x, y, z, dp);

    ans = solveRecMem2(dp, nums, n, 0);

    if (ans < 0)
    {
        return 0;
    }

    return ans;
}

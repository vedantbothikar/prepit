#include <bits/stdc++.h>

int solveRec(vector<int> &nums, vector<int> &dp, int index)
{

    // base case
    if (index >= nums.size())
    {
        return 0;
    }

    // check dp
    if (dp[index] != -1)
    {
        return dp[index];
    }

    // include
    // increment index by 2, add nums[index] to the includeSum
    int includeSum = nums[index] + solveRec(nums, dp, index + 2);

    // exclude
    // increment index by 1
    int excludeSum = solveRec(nums, dp, index + 1);

    // calculate ans and populate dp
    dp[index] = max(includeSum, excludeSum);
    return dp[index];
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.

    vector<int> dp(nums.size() + 1, -1);
    return solveRec(nums, dp, 0);
}
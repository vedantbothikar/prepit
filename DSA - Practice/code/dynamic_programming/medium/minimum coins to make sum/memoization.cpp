#include <bits/stdc++.h>
using namespace std;

/*

DYNAMIC PROGRAMMING SOLUTION

In previous solution we were calculating if the number could be an answer or not
for every number in the vector
So we have overlapping subproblems
So we can reduce the time required by using DP


What can be stored in dp array?




*/
int solveMem(vector<int> &num, int target, vector<int> &dp)
{

    // base case
    if (target == 0)
    {
        return 0;
    }

    if (target < 0)
    {
        return INT_MAX;
    }

    // check dp
    if (dp[target] != -1)
    {
        return dp[target];
    }

    int mini = INT_MAX;

    // check every possible case
    for (int i = 0; i < num.size(); i++)
    {

        int count = solveMem(num, target - num[i], dp);

        if (count != INT_MAX)
        {
            mini = min(mini, count + 1);
        }
    }

    // store in dp
    dp[target] = mini;
    return mini;
}

int main()
{

    vector<int> dp(target + 1, -1);

    // MEMOIZATION
    int ans = solveMem(num, target, dp);
    if (ans == INT_MAX)
        return -1;
    return ans;

    return 0;
}
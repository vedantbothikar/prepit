#include <bits/stdc++.h>
using namespace std;

/*

Problem: https://www.codingninjas.com/studio/problems/frog-jump_3621012
Solution: https://youtu.be/EgG3jsGoPvQ?si=dzKCVH0XBnoOYLny


Here greedy solution will not work because it can miss things

*/

int solveRecMem(int n, vector<int> &heights, vector<int> &dp)
{

    // base cases
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return abs(heights[1] - heights[0]);
    }

    // check in dp
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // choices
    int oneJump = abs(heights[n] - heights[n - 1]) + solveRecMem(n - 1, heights, dp);
    int twoJump = abs(heights[n] - heights[n - 2]) + solveRecMem(n - 2, heights, dp);

    // populate in dp
    return dp[n] = min(oneJump, twoJump);
}

int solveTab(int n, vector<int> &heights, vector<int> &dp)
{

    // bottom up solution

    if (n == 0)
        return 0;
    if (n == 1)
        return abs(heights[1] - heights[0]);

    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);

    for (int i = 2; i <= n; i++)
    {

        // choices
        int oneJump = abs(heights[i] - heights[i - 1]) + dp[i - 1];
        int twoJump = abs(heights[i] - heights[i - 2]) + dp[i - 2];

        dp[i] = min(oneJump, twoJump);
    }

    return dp[n];
}

int solveSpaceOpt(int n, vector<int> &heights, vector<int> &dp)
{

    // space optimization solution

    if (n == 0)
        return 0;
    if (n == 1)
        return abs(heights[1] - heights[0]);

    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);

    int prev1 = dp[1];
    int prev2 = dp[0];

    for (int i = 2; i <= n; i++)
    {

        // choices
        int oneJump = abs(heights[i] - heights[i - 1]) + prev1;
        int twoJump = abs(heights[i] - heights[i - 2]) + prev2;

        dp[i] = min(oneJump, twoJump);

        // update
        prev2 = prev1;
        prev1 = dp[i];
    }

    return dp[n];
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.

    vector<int> dp(n + 1, -1);

    // memoization solution
    // we are passing n-1 here because it is mentioned in the question that the frog starts from the 1st step
    // return solveRecMem(n-1, heights, dp);

    // tabulation solution
    // return solveTab(n-1, heights, dp);

    // space optimization solution
    return solveSpaceOpt(n - 1, heights, dp);
}

int main()
{

    return 0;
}
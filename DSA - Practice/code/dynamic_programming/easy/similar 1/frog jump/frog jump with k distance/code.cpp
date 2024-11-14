#include <bits/stdc++.h>
using namespace std;

/*

Code problem: https://www.codingninjas.com/studio/problems/minimal-cost_8180930
Youtube video Striver: https://www.youtube.com/watch?v=Kmh3rhyEtB8&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=5


*/

int solveRecMem(int n, int k, vector<int> &height, int index, vector<int> &dp)
{

    // base cases
    if (index == 0)
    {
        return 0;
    }

    // check in dp
    if (dp[index] != -1)
    {
        return dp[index];
    }

    // possibilities
    int minAns = INT_MAX;
    for (int i = 1; i <= k; i++)
    { // i indicates we are descending i stones

        int latestStepCost = abs(height[index] - height[index - i]);
        int currentAns = INT_MAX;

        if (index - i >= 0)
        {
            currentAns = latestStepCost + solveRecMem(n, k, height, index - i, dp); // latestStepCost + costOfComingTill index-i
        }
        minAns = min(minAns, currentAns);
    }

    // populate dp
    return dp[index] = minAns;
}

int minimizeCost(int n, int k, vector<int> &height)
{
    // Write your code here.

    n = n - 1; // do this because according to qs we are starting from stone 1
    int index = n;
    vector<int> dp(n + 1, -1);

    return solveRecMem(n, k, height, index, dp);
}

int main()
{

    return 0;
}
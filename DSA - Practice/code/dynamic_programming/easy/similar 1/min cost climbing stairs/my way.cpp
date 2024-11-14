#include <bits/stdc++.h>
using namespace std;

/*

We have to find the cost to reach the top
but to reach the top we need to find the min cost of reaching the top-1 and top-2

so this keeps repeating which means we can use recursion


AND
there are overlapping subproblems
so we can also use dp to optimize

TC O(N)
SC 2*O(N)


*/

class Solution
{
public:
    int solve(vector<int> &cost, int n, vector<int> &dp)
    {

        // base case
        if (n == 0 or n == 1)
        {
            return cost[n];
        }

        // check dp
        if (dp[n] != -1)
        {
            return dp[n];
        }

        dp[n] = cost[n] + min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
        return dp[n];
    }

    int minCostClimbingStairs(vector<int> &cost)
    {

        // for which cost to find?
        int n = cost.size();

        vector<int> dp(n + 1, -1); // initialize to -1

        // making cost of n+1 as 0
        cost.push_back(0);

        return solve(cost, n, dp);
    }
};

int main()
{

    return 0;
}
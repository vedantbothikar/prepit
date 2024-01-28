#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // DYNAMIC PROGRAMMING
    /*

    There are can be 2 cases when the coin is considered or not considered

    We will have a 2d dp array in which we will store the answer(minimum number of coins) for the specified index

        What is specified index?
    -> This is the index at which we are currently traversing... so it will kind of like tell us the solution to the subproblem


    */

    int solve(vector<int> &coins, int target, int index, vector<vector<int>> &dp)
    {

        // base case
        if (target == 0)
        {
            return 0;
        }

        if (index == coins.size())
        { // we are returning 1e9 and not INT_MAX because in include statement we are adding 1 to it.. so it will give integer overflow error when we add
            return 1e9;
        }

        if (target < 0)
        {
            return 1e9;
        }

        // check dp
        if (dp[index][target] != -1)
        {
            return dp[index][target];
        }

        // There are 2 possibilities: whether to take the current element or not to take

        // CASE 1: When the coin is considered
        // dont increment index: because we can consider the element once again (read question, we can include the same coin unlimited number of times)
        // if we keep taking these coins, then target will keep reducing and the base case will hit AND here also reduce the target by coins[i]
        // we should also add 1 here because we are considering this coin - so add 1
        int include = 1 + solve(coins, target - coins[index], index, dp);

        // CASE 2: Dont take the coin
        // Here we increment the index so that we can go to next coin
        // if we keep exlcuding the coins, then base case of index greater than size will reach
        int exclude = solve(coins, target, index + 1, dp);

        dp[index][target] = min(include, exclude);
        return dp[index][target];
    }

    int coinChange(vector<int> &coins, int target)
    {

        // initialize a 2d vector of coinSize X target and initialize it to -1
        vector<vector<int>> dp(coins.size() + 1, vector<int>(target + 1, -1));

        int ans = solve(coins, target, 0, dp);

        if (ans == 1e9)
            return -1;
        return ans;
    }
};

int main()
{

    return 0;
}
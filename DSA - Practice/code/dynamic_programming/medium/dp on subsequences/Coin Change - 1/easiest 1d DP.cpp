/*

- https://leetcode.com/problems/coin-change/description/

Check this solution:
https://leetcode.com/problems/coin-change/solutions/6052329/c-solution-using-1d-dp/

*/


class Solution {

    int solve(vector<int>& coins, int amount, int index, vector<int>& dp) {

        // base condition
        if(amount == 0) return 0;

        if(index == coins.size()) return 1e9;

        if(amount < 0) return 1e9;

        // check in dp
        if(dp[amount] != -1) return dp[amount];

        // logic
        int res = 1e9;
        for(int i = index; i < coins.size(); i++) {

            int currCoins = 1 + solve(coins, amount - coins[i], index, dp); // not incrementing index since we can take the same coin again
            res = min(res, currCoins);
        }
        
        return dp[amount] = res;
    }

public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount+1, -1);
        int index = 0;

        int ans = solve(coins, amount, index, dp);

        return ans == 1e9 ? -1 : ans;
    }
};
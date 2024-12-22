/*


Prefer this solution

- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
- https://neetcode.io/solutions/best-time-to-buy-and-sell-stock-with-cooldown

TC: O(n)
SC: O(n)


*/

class Solution {
    int solve(vector<int>& prices, int index, int canBuy, vector<vector<int>>& dp) {
        // Base condition
        if (index >= prices.size()) return 0;

        // Check in dp
        if (dp[index][canBuy] != -1) {
            return dp[index][canBuy];
        }

        int profit = 0;
        if (canBuy) {
            // We can either buy or skip
            int buy = -prices[index] + solve(prices, index + 1, 0, dp);
            int skip = solve(prices, index + 1, 1, dp);
            profit = max(buy, skip);
        } else {
            // We can either sell or skip
            int sell = prices[index] + solve(prices, index + 2, 1, dp); // Cooldown of 1 day
            int skip = solve(prices, index + 1, 0, dp);
            profit = max(sell, skip);
        }

        return dp[index][canBuy] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1)); // dp[index][canBuy]
        return solve(prices, 0, 1, dp); // Start at index 0, with the ability to buy
    }
};

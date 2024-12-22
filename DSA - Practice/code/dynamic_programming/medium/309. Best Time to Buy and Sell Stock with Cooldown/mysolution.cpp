/*

This solution passess all cases except one last case in leetcode
The last cases gives a TLE

- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

Here a combination of index and buyingInd is used as key for dp


*/

class Solution {

    int solve(vector<int>& prices, int index, int buyingInd, unordered_map<string, int>& dp) {

        // base condition
        if(index >= prices.size()) return 0;

        // check in dp
        string key = to_string(index) + "#" + to_string(buyingInd);
        if(dp.find(key) != dp.end()) {
            return dp[key];
        }

        int sell = 0, notSell = 0, buy = 0, notBuy = 0;
        // possibilities
        if(buyingInd != -1) {

            // sell or not sell
            int currProfit = prices[index]-prices[buyingInd];
            sell = currProfit + solve(prices, index+2, -1, dp);

            notSell = solve(prices, index+1, buyingInd, dp);
        }
        else {

            // buy or not buy
            buy = solve(prices, index+1, index, dp);
            notBuy = solve(prices, index+1, buyingInd, dp);
        }

        return dp[key] = max(sell, max(notSell, max(buy, notBuy)));
    }

public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        unordered_map<string, int> dp;

        return solve(prices, 0, -1, dp);
    }
};
/*

    Problem Statement: https://leetcode.com/problems/paint-house/
    Difficulty: Medium
    Topic: Dynamic Programming

*/


class Solution {

    int solve(vector<vector<int>>& costs, int index, int color, vector<vector<int>>& dp) {

        // base case
        if(index == 0) return costs[index][color];

        // check in dp
        if(dp[index][color] != -1) return dp[index][color];

        // possibilities
        int minCost = 0;
        if(color == 0) {
            int currCost = costs[index][color];
            int adjHouseOpt1 = solve(costs, index-1, 1, dp);
            int adjHouseOpt2 = solve(costs, index-1, 2, dp);

            minCost = currCost + min(adjHouseOpt1, adjHouseOpt2);
        }
        else if(color == 1) {
            int currCost = costs[index][color];
            int adjHouseOpt1 = solve(costs, index-1, 0, dp);
            int adjHouseOpt2 = solve(costs, index-1, 2, dp);
            
            minCost = currCost + min(adjHouseOpt1, adjHouseOpt2);
        }
        else {
            int currCost = costs[index][color];
            int adjHouseOpt1 = solve(costs, index-1, 0, dp);
            int adjHouseOpt2 = solve(costs, index-1, 1, dp);
            
            minCost = currCost + min(adjHouseOpt1, adjHouseOpt2);
        }

        return dp[index][color] = minCost;
    }


public:
    int minCost(vector<vector<int>>& costs) {
        
        int n = costs.size();   // number of houses
        vector<vector<int>> dp(n, vector<int>(3, -1));

        int lastHouseIdx = n - 1;
        
        // possibilities
        int lastRed = solve(costs, lastHouseIdx, 0, dp);
        int lastBlue = solve(costs, lastHouseIdx, 1, dp);
        int lastGreen = solve(costs, lastHouseIdx, 2, dp);

        return min(lastRed, min(lastBlue, lastGreen));
    }
};
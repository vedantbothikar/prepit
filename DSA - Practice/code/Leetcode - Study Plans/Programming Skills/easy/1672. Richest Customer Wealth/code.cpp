/*
- https://leetcode.com/problems/richest-customer-wealth/?envType=study-plan-v2&envId=programming-skills

*/


class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int maxWealth = INT_MIN;
        int n = accounts.size();
        int m = accounts[0].size();

        for(int i = 0; i < n; i++) {

            int currWealth = 0;
            for(int j = 0; j < m; j++) {
                currWealth += accounts[i][j];
            }

            maxWealth = max(maxWealth, currWealth);
        }

        return maxWealth;
    }
};
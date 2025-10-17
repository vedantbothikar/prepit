/*

Problem Link: https://leetcode.com/problems/shopping-offers/description/

*/


class Solution {

    int calcCost(vector<int>& needs, vector<int>& price) {

        int n = needs.size();
        int cost = 0;
        for(int i = 0; i < n; i++) {
            cost += needs[i] * price[i];
        }
        return cost;
    }

    bool validOffer(vector<int>& needs, vector<int>& offer) {

        for(int i = 0; i < needs.size(); i++) {
            if(needs[i] - offer[i] < 0) return false;
        }

        return true;
    }

    vector<int> getNewNeeds(vector<int>& needs, vector<int>& offer) {

        int n = needs.size();
        vector<int> newNeeds(n, 0);
        for(int i = 0; i < n; i++) {
            newNeeds[i] = needs[i] - offer[i];
        }

        return newNeeds;
    }

    int solve(vector<int>& price, vector<vector<int>>& special, vector<int>& needs,  map<vector<int>, int>& dp) {

        // check in dp
        if(dp.find(needs) != dp.end()) return dp[needs];

        int minCost = INT_MAX;

        // CASE 1: find the total cost without using any special offer
        int costWithoutOffer = calcCost(needs, price);
        minCost = min(minCost, costWithoutOffer);

        // CASE 2: now try for all special offers
        for(auto offer : special) {

            if(!validOffer(needs, offer)) continue;

            vector<int> newNeeds = getNewNeeds(needs, offer);
            int costOfNewNeeds = solve(price, special, newNeeds, dp);
            int costWithCurrOffer = offer.back() + costOfNewNeeds;

            minCost = min(minCost, costWithCurrOffer);
        }
        
        return dp[needs] = minCost;
    }

public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        
        map<vector<int>, int> dp;
        return solve(price, special, needs, dp);
    }
};
/*

2 pointer technique:
- solution: https://www.youtube.com/watch?v=1pkOgXD63yU&ab_channel=NeetCode

left, right pointers

left: day we buy 
right: day we sell

this means that our left should always be less than right
so whenever right becomes lower than left, update left be equal to right

and loop on right to keep checking the maxDiff


*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int left = 0;    // indicates indices
        int maxDiff = INT_MIN;

        for(int right = 1; right <= prices.size()-1; right++) {

            maxDiff = max(maxDiff, prices[right] - prices[left]);

            if(prices[right] < prices[left]) left = right;
        }

        return maxDiff > 0 ? maxDiff : 0;
    }
};
/*

Brute force:
O(n^2)
for i 0 to n
    find the difference between every other element in rest of the array
        keep updating the maxDiff


Better:

find the initial diff using prices[1] - prices[0]
make this as maxdiff
keep minElement starting from prices[0]

while we reach end
    maxDiff = max(maxDiff, prices[i]-minElement);
    minElement = min(minElement, prices[i]);

instead can we start from 0?
minElement initially is INT_MAX
maxDiff initially is INT_MIN



*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minElement = INT_MAX;
        int maxDiff = INT_MIN;

        for(int i = 0; i < prices.size(); i++) {

            maxDiff = max(maxDiff, prices[i]-minElement);
            minElement = min(minElement, prices[i]);
        }
        
        return maxDiff > 0 ? maxDiff : 0;
    }
};
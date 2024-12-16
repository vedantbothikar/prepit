/*

- https://leetcode.com/problems/trapping-rain-water/description/

precompute list of max heights on left
precompute list of max heights on right

for every position:
waterAtCurrLevel = min(lheight[i], rheight[i]) - height[i]

which means the minimum of the max heights on left or right side minus the height of the current position will be the water level at the current position

How to compute the max height from left?
traverse from left, keep a track of maxHeight so far and update the values
The maxheight for 0th position will be: the curr height itself


TC: O(n)
SC: O(n)

*/
class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        vector<int> lheight(n);
        lheight[0] = height[0];

        for(int i = 1; i < n; i++) {

            lheight[i] = max(lheight[i-1], height[i]);
        }

        vector<int> rheight(n);
        rheight[n-1] = height[n-1];

        for(int i = n-2; i >= 0; i--) {

            rheight[i] = max(rheight[i+1], height[i]);
        }
        
        int totalWater = 0;
        for(int i = 0; i < n; i++) {
            
            totalWater += min(lheight[i], rheight[i]) - height[i];
        }

        return totalWater;
    }
};
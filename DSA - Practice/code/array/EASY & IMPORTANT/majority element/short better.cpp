/*

BETTER SOLUTION: (Not Optimal)

- Sort the elements

Now because the element occurs more than n/2 times, so the element 
will also always be at the middle of the array


*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
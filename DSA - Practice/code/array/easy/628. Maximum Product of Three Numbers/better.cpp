/*

- https://leetcode.com/problems/maximum-product-of-three-numbers/description/
- Solution: https://leetcode.com/problems/maximum-product-of-three-numbers/solutions/6118717/c-solution-using-sorting

*/


/*

Better solution:
SORTING:
Options:
- take starting 2 nums, and the last largest one
    int op1 = nums[0] * nums[1] * nums[n-1];
- take last 3 nums
    int op2 = nums[n-1] * nums[n-2] * nums[n-3];

return max(op1, op2);

TC: O(nlogn)
SC: O(1)

*/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int op1 = nums[0] * nums[1] * nums[n-1];
        int op2 = nums[n-1] * nums[n-2] * nums[n-3];

        return max(op1, op2);
    }
};
/*

- https://leetcode.com/problems/maximum-product-of-three-numbers/description/
- https://leetcode.com/problems/maximum-product-of-three-numbers/solutions/6118763/c-solution-in-single-pass-o-n
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


OPTIMAL SOLUTION:
From the better solution, we observe that we just need the first 2 minimum elements and last 3 maximum elements to get our answer. Then instead of sorting, why dont we just check for these elements in the array in a single pass, and then find the answer?


*/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        // min1 < min2
        // max1 > max2 > max3
        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

        // find min1, min2, max1, max2, max3 in a single pass
        // NOTE: make sure to add equal to sign in the conditions, because if we have duplicates, same duplicates can be max1, max2, max3, etc (take an example to understand it)
        for(int num : nums) {

            if(num <= min1) {
                min2 = min1;
                min1 = num;
            }
            else if(num <= min2) { // num is > min1, but < min2
                min2 = num;
            }

            if(num >= max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if(num >= max2) {   // if num is > max but less than max1
                max3 = max2;
                max2 = num;
            }
            else if(num >= max3) {
                max3 = num;
            }
        }
        
        int op1 = min1 * min2 * max1;
        int op2 = max1 * max2 * max3;

        return max(op1, op2);
    }
};
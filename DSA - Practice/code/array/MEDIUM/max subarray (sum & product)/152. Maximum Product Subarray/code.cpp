/*

- https://leetcode.com/problems/maximum-product-subarray/
- https://neetcode.io/solutions/maximum-product-subarray

TC: O(n)
SC: O(1)


here it is similar to max sum subarray, the only difference is that
we need to maintain the minProd as well. The reason for this 
is that if a number is negative, if we multiply it with a 
negative number we will get a positive number that is begger
So we need to maintain the minprod and check if the 
current negative num if multiplied with currMin (which lets say assume is negative)
then we will get a positive number and could potentially we greater than currMax

*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int ans = nums[0];
        int currMax = 1;
        int currMin = 1;
        
        for(int num : nums) {

            int temp = num * currMax;

            currMax = max(num, max(num * currMax, num * currMin));
            currMin = min(num, min(temp, num * currMin));   // use temp here since currMax has now changed

            ans = max(ans, currMax);
        }

        return ans;
    }
};
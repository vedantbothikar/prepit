
/*

- https://leetcode.com/problems/missing-number/description/

Approach:
XOR each number in the nums array and also all the numbers 
from 0 to n. And XOR two numbers which are same gives 0, so 
whichever number is appears only once will give us the final output.

Time complexity: O(N)
Space complexity: O(1)

*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        int ans = nums[0];
        
        ans = ans ^ 0;
        for(int i = 1; i < nums.size(); i++) {

            ans = ans ^ nums[i] ^ i;
        }

        ans = ans ^ n;
        return ans;
    }
};
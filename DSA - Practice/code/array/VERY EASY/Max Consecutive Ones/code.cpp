/*

APPROACH:
- Traverse the array
- If element is equal to 1, then increase the count
- if you get anything other than 1, then reset count to 0 and set maxCount = max(maxCount, count)


*/


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int maxCount = 0;
        int count = 0;

        for(int i=0; i<nums.size(); i++) {

            if(nums[i] == 1) count++;
            else {

                maxCount = max(maxCount, count);
                count = 0;
            } 
        }
        
        return max(maxCount, count);
    }
};
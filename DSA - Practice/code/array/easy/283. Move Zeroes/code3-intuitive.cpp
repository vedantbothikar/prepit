/*

2 pointers
left, right

left -> position where we have to copy the nonzero element
right -> using which we traverse the array

when right reaches the end, then all elements from left to end will be zero

*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int n = nums.size();
        int left = 0, right = 0;
        
        while(right < n) {

            if(nums[right] != 0) {
                nums[left] = nums[right];
                left++;
            }

            right++;
        }

        // mark all remaining as zero
        while(left < n) {
            nums[left] = 0;
            left++;
        }
    }
};
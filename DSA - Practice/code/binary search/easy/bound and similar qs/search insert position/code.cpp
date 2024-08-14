
/*

https://leetcode.com/problems/search-insert-position/description/

VIDEO: https://www.youtube.com/watch?v=6zhGS79oQ4k

*/


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int n = nums.size();
        int start = 0;
        int end =  n - 1;
        int ans = n;

        while(start <= end) {

            int mid = start + (end - start)/2;

            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] >= target) {
                ans = mid;
                end = mid - 1;  // similar to lower bound question, find the smallest index of element that is just greater than the target
            }
            else {
                start = mid + 1;
            }
        }

        return ans;        
    }
};
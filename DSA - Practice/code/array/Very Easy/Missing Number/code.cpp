/*

PROBLEM: https://leetcode.com/problems/missing-number/


Approach:
- sort the array O(nlogn) 
- traverse the array one by one
    - check which number is missing by comparing it with i
    - if number is missing return that number

TC: O(nlogn)

*/


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++) {

            if(i != nums[i]) {
                return i;
            }
        }

        return nums.size();
    }
};
/*

PROBLEM: https://leetcode.com/problems/missing-number/
- https://leetcode.com/problems/missing-number/solutions/4754401/beats-98-users-4-approaches-c-java-python-javascript-explained/


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

/*

# APPROACH:

Problem: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

Alternate solution: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/solutions/5224249/efficient-easy-to-understand-c-code-beats-100/


- sort the original array and keep that as array B
- find the position of smallest element in the array A (which should be equal to
zeroth element of B)

   // TBD: handle case when smallest element of both arrays are in the zeroth
location from this position go to the end of the list as you go ahead
- check if the element of both the arrays are equal - if not - return false

use this equation to check if the elements are equal or not:
A[i] == B[(i+x) % A.length]

TC O(NlogN)


*/

class Solution {
public:
    bool check(vector<int>& nums) {

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());     // This will take O(NlogN) time

        if (nums == sorted)
            return true;

        // traverse to find the position of smallest element
        int startPos = 0;

        bool duplicateNumsCase = false;
        bool nowStartSearching = false;    

        if (nums[0] == sorted[0])
            duplicateNumsCase = true;

// This special check for duplicateNums is specifically when the starting element of nums and sorted are the same and there are many duplicates of this particular element
// EXAMPLE CASES: [6,10,6] [2,2,3,4,5,2] [1,2,1,1]
        if (duplicateNumsCase) {

            for(int i=1; i<nums.size(); i++) {

                if(nums[i] != sorted[0]) {
                    nowStartSearching = true;
                }

                if(nowStartSearching and (nums[i] == sorted[0])) {
                    startPos = i;
                    break;
                }
            }

        } else {    // This is for all other normal cases
            for (int i = 0; i < nums.size(); i++) {

                if (sorted[0] == nums[i]) {
                    startPos = i;
                    break;  // break is req for this CASE: [7,9,1,1,1,3]
                }
            }
        }

        // traverse to check if elements are equal
        int vecSize = nums.size();
        for (int i = 0; i < vecSize; i++) {

            if (nums[(i + startPos) % vecSize] != sorted[i])
                return false;
        }

        return true;
    }
};

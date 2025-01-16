/*

- https://leetcode.com/problems/missing-ranges/?envType=study-plan-v2&envId=programming-skills

range of lower, upper (inclusive)

we want to find the ranges which are missing from the nums

Logic:
from lower to first num: 
    - check if lower == num:
        continue
    - else if not equal:
        this is one of the ranges


new array:
lower, ...nums, upper

missing ranges

lower+1 to nums[i]-1 

CASES:
    - if lower == nums[i]: skip (do nothing)
    - else if nums[i] == lower+1: skip (do nothing)
    - else: (this means there is a gap)
        // add the missing range
        [lower+1, nums[i]-1]


// prepare for next iteration
lower = nums[i]
i++

*/
class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {

        int n = nums.size();
        vector<vector<int>> ans;

        if(n == 0) {
            // the whole range is missing
            ans.push_back({lower, upper});
            return ans;
        }

        // solve for first check: btwn lower and nums[0]
        // if lower == nums[0]: do nothing
        // if lower != nums[0]: missing range lower to nums[0]-1
        if(lower != nums[0]) {
            cout << "initial check failed" << endl;
            ans.push_back({lower, nums[0]-1});
            lower = nums[0];
        }

        for(int i = 1; i < n; i++) {

            if(lower == nums[i] or lower+1 == nums[i]) {
                // skip, do nothing
                lower = nums[i];
                continue;
            }
            
            // when there is a gap
            ans.push_back({lower+1, nums[i]-1});
            lower = nums[i];
        }

        // solve for last check
        int lastInd = n-1;
        if(nums[lastInd] != upper) {
            cout << "last check failed" << endl;
            // there is a gap
            ans.push_back({nums[lastInd]+1, upper});
        }

        return ans;
    }
};
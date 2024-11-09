/*

- https://leetcode.com/problems/combination-sum-ii/
- Check neetcode video: https://www.youtube.com/watch?v=FOyRpNUSFeA&ab_channel=NeetCodeIO


NOTE: This solution will NOT give Memory Exceeded error, since we are skipping duplicates

Complexity
Time complexity: O(n * 2^n)
Space complexity: O(n)

*/

class Solution {

    void solve(vector<int>& nums, int target, int index, vector<int> current,
               vector<vector<int>>& ans) {

        // base condition
        if (index >= nums.size()) {

            if (target == 0) {
                ans.push_back(current);
            }

            return;
        }

        // pick
        if (nums[index] <= target) {
            current.push_back(nums[index]);
            solve(nums, target - nums[index], index + 1, current, ans);
            current.pop_back();
        }

        // not pick
        // In this case: we have to skip the duplicates (for exmaple if input was: 1,1,2) then we want to skip all 1s and go to 2

        while((index+1 < nums.size() && (nums[index] == nums[index+1]))) {
            index++;
        }
        solve(nums, target, index + 1, current, ans);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {

        vector<int> current;
        vector<vector<int>> ans;

        // sort now so that later when we put it in set, the vectors internally
        // are sorted and we can get unique vectors
        sort(nums.begin(), nums.end());

        solve(nums, target, 0, current, ans);

        return ans;
    }
};
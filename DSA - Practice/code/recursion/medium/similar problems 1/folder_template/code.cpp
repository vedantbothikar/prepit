/*

- https://leetcode.com/problems/combination-sum-ii/
- Check neetcode video: https://www.youtube.com/watch?v=FOyRpNUSFeA&ab_channel=NeetCodeIO


NOTE: This solution WILL give Memory Exceeded error, since we are using a set (I didnt understand the reason properly though)

Complexity
Time complexity: O(n * 2^n)
Space complexity: O(n * 2^n)

*/

class Solution {

    void solve(vector<int>& nums, int target, int index, vector<int> current, vector<vector<int>>& finalAns) {

        // base condition
        if(index >= nums.size()) {

            if(target == 0) {
                finalAns.push_back(current);
            }
            
            return;
        }

        // pick 
        current.push_back(nums[index]);
        solve(nums, target-nums[index], index+1, current, finalAns);
        current.pop_back();

        // not pick
        solve(nums, target, index+1, current, finalAns);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        
        vector<int> current;
        vector<vector<int>> finalAns;

        // sort now so that later when we put it in set, the vectors internally are sorted and we can get unique vectors
        sort(nums.begin(), nums.end());


        solve(nums, target, 0, current, finalAns);

        // store in a set so that we only get unique vectors
        set<vector<int>> s(finalAns.begin(), finalAns.end());
        
        finalAns.clear();
        finalAns.assign(s.begin(), s.end());

        return finalAns;
    }
};
class Solution {

    void solve(vector<int>& nums, int index, vector<int> current, vector<vector<int>>& ans) {

        // base condition
        if(index >= nums.size()) {
            ans.push_back(current);
            return;
        }

        // pick 
        current.push_back(nums[index]);
        solve(nums, index+1, current, ans);
        current.pop_back();

        // not pick
        solve(nums, index+1, current, ans);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<int> current;
        vector<vector<int>> ans;

        // sort so that you can later remove duplicates
        sort(nums.begin(), nums.end());

        solve(nums, 0, current, ans);

        // Remove duplicates

        // Step1: push to a set
        set<vector<int>> s(ans.begin(), ans.end());

        // Step 2: put back to vector
        vector<vector<int>> finalAns(s.begin(), s.end());

        return finalAns;
    }
};
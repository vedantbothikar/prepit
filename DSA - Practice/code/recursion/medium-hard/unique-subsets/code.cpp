class Solution
{
public:
    /*

    we can calculate all the subsets
    but how to remove the duplicates?


    */

    void solve(vector<int> &nums, vector<int> subans, vector<vector<int>> &ans, int count)
    {

        // base case
        if (count >= nums.size())
        {
            sort(subans.begin(), subans.end());
            ans.push_back(subans);
            return;
        }

        // exclude
        solve(nums, subans, ans, count + 1);

        // include
        subans.push_back(nums[count]);
        solve(nums, subans, ans, count + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {

        int count = 0;
        vector<int> subans;
        vector<vector<int>> ans;

        solve(nums, subans, ans, count);

        // remove duplicate
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};
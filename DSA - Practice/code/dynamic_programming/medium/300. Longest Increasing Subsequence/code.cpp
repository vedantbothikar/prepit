/*

- https://leetcode.com/problems/longest-increasing-subsequence/description/
- https://neetcode.io/solutions/longest-increasing-subsequence


Complexity
Time complexity: O(n^2)
n possible values for array index
n possible values for prevInd

Space complexity: O(n^2)

combinations: recursion: include-exclude technique

we need to keep track of prev num

// base conditions:
if(index >= n) return 0

if curr < prev: we dont want this subsequence
    -> return 0

// logic
int include = 1 + solve(index+1, prev = nums[index])
int exclude = solve(index+1, prev = prev)

return max(include, exclude);
*/
class Solution {

    int solve(vector<int>& nums, int index, int prevInd, vector<vector<int>>& dp) {

        // base conditions
        if(index >= nums.size()) return 0;

        // check in dp
        if(prevInd != -1 && dp[index][prevInd] != -1) return dp[index][prevInd];

        // logic: include-exclude
        int include = 0;
        if(prevInd == -1 || nums[index] > nums[prevInd]) { // here we can include as well as exclude

            include = 1 + solve(nums, index+1, index, dp);
        }

        int exclude = solve(nums, index+1, prevInd, dp);

        // store in dp: only if prevInd is != -1
        if(prevInd != -1) dp[index][prevInd] = max(include, exclude);

        return max(include, exclude);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));  // dp of index and prevIndex
        int index = 0;
        int prevInd = -1;   // initially pass -1 as prevIndex

        return solve(nums, 0, prevInd, dp);    
    }
};
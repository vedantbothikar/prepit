/*


- https://leetcode.com/problems/target-sum/
- https://neetcode.io/solutions/target-sum

You have 2 options:
to add the current number or to subtract

// base conditons:
if(target == 0)

if(target < 0)

if(index out of bounds)

int add = 
int subtract = 


return add + subtract

*/
class Solution {

    int totSum = 0;
    int solve(vector<int>& nums, int target, int currSum, int index, vector<vector<int>>& dp) {

        // base conditions:
        if(target == currSum && index == nums.size()) return 1;

        if(index >= nums.size()) return 0;

        // check in dp
        if(dp[index][currSum+totSum] != -1) return dp[index][currSum+totSum];

        // possibilities
        int add = solve(nums, target, currSum-nums[index], index+1, dp);
        int subtract = solve(nums, target, currSum+nums[index], index+1, dp);

        return dp[index][currSum+totSum] = add + subtract;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        totSum = accumulate(nums.begin(), nums.end(), 0);

        int colSize = 2*totSum + 1;

        vector<vector<int>> dp(n+1, vector<int>(colSize, -1));
        return solve(nums, target, 0, 0, dp);
    }
};
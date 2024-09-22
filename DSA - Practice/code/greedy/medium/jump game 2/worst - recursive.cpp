/*

- https://leetcode.com/problems/jump-game-ii/description/
- https://www.youtube.com/watch?v=7SBVnw7GSTk

TC: O(n^N)
TLE


*/

class Solution {
    int solve(vector<int>& nums, int index, int jumps) {
        // Base case: when we reach or exceed the last index
        if (index >= nums.size() - 1) {
            return jumps;
        }

        int mini = INT_MAX;

        // Loop through all possible jumps from this position
        for (int i = 1; i <= nums[index] && index + i < nums.size(); i++) {
            int currJumps = solve(nums, index + i, jumps + 1);
            mini = min(mini, currJumps);
        }

        return mini;
    }

public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;  // No jumps needed if there's only one element
        
        return solve(nums, 0, 0);
    }
};


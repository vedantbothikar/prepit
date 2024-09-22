/*

TC: O(N^2)
Explanation for TC:
### Time Complexity of the DP Solution:

The time complexity of the DP solution is **O(n²)**, where `n` is the size of the input array `nums`. 

### Explanation of the Time Complexity:

1. **Recursion with Memoization**:
   - The function `solve(nums, index, dp)` is called recursively, and for each index, you iterate over the possible jumps.
   - The memoization (`dp` array) ensures that each index is only computed once. Once a result is computed for a given index, it is stored in `dp[index]`, and subsequent calls for the same index directly return the stored value.

2. **Looping Over Possible Jumps**:
   - For each index `i`, you loop through all possible jumps, i.e., you try jumping to positions `i + 1`, `i + 2`, ..., up to `i + nums[i]` (as long as you remain within bounds).
   - In the worst case, from each index `i`, you could potentially jump to any of the remaining positions up to the end of the array. Therefore, for each index, you perform **up to `n - i` operations** (where `n` is the length of the array).
   
3. **Summing Over All Indices**:
   - In the worst case, you have to explore multiple paths for each index, resulting in a quadratic time complexity.
   - For example:
     - At index 0, you may jump to up to `n - 1` positions.
     - At index 1, you may jump to up to `n - 2` positions.
     - At index 2, you may jump to up to `n - 3` positions.
     - And so on.
   - The sum of all possible jumps across the array is approximately **O(n²)**.

### Step-by-step Time Complexity Analysis:

- **Outer Loop (Recursive Call)**:
  - The recursion starts at `index = 0` and proceeds for all other indices, calling the `solve` function for each.
  
- **Inner Loop (Exploring Jumps)**:
  - For each index `i`, the number of possible jumps depends on `nums[i]`. In the worst case, for every index, you may jump to every subsequent index in the array.
  
Thus, in the worst case, the total number of operations can be summarized as:

\[
O(n - 1) + O(n - 2) + O(n - 3) + ... + O(1) = O(n^2)
\]

### Summary:

- The outer recursion has **O(n)** calls (one for each index in the array).
- For each recursive call, the inner loop can make **up to O(n)** jumps (in the worst case).
- This results in an overall time complexity of **O(n²)**.

The memoization helps prevent re-computation of subproblems, but since we are exploring multiple possible jumps from each index, the overall complexity remains **O(n²)** in the worst case.


*/

class Solution {

    int solve(vector<int>& nums, int index, vector<int>& dp) {

        // base case: when we reach to the end of the array
        if (index >= nums.size() - 1) {
            return 0;
        }

        // check in dp
        if(dp[index] != -1) return dp[index];

        int mini = INT_MAX;

        for (int i = 1; i <= nums[index] && index + i < nums.size(); i++) {

            int currJumps = solve(nums, index + i, dp);
            if (currJumps != INT_MAX) mini = min(mini, currJumps + 1);
        }

        return dp[index] = mini;
    }

public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;

        vector<int> dp(nums.size(), -1);

        return solve(nums, 0, dp);
    }
};
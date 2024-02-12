
int solveSpaceOptimization(vector<int> &nums, vector<int> &dp)
{

    int lastIndex = nums.size() - 1;
    int n = nums.size();

    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return nums[0];
    }

    // initialize dp array
    dp[lastIndex] = nums[lastIndex];
    dp[lastIndex - 1] = max(nums[lastIndex], nums[lastIndex - 1]);

    int next1 = dp[lastIndex - 1];
    int next2 = dp[lastIndex];

    for (int i = n - 3; i >= 0; i--)
    {

        int includeSum = nums[i] + next2;
        int excludeSum = next1;
        dp[i] = max(includeSum, excludeSum);

        // update
        next2 = next1;
        next1 = dp[i];
    }

    return dp[0];
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.

    // vector<int> dp(nums.size()+1, -1);
    // return solveRec(nums, dp, 0);

    vector<int> dp(nums.size() + 1, 0);
    return solveMem(nums, dp);

    // space optimization
    // vector<int> dp(nums.size()+1, 0);
    // return solveSpaceOptimization(nums, dp);
}
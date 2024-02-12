
int solveMem(vector<int> &nums, vector<int> &dp)
{

    // tabulation approach
    // bottom up approach

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

    for (int i = n - 3; i >= 0; i--)
    {

        int includeSum = nums[i] + dp[i + 2];
        int excludeSum = dp[i + 1];
        dp[i] = max(includeSum, excludeSum);
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

    // vector<int> dp(nums.size()+1, 0);
    // return solveMem2(nums, dp);
}
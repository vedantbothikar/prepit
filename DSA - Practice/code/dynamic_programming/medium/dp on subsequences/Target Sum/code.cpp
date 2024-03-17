#include <bits/stdc++.h> 


/*

https://www.codingninjas.com/studio/problems/target-sum_4127362

ALSO WATCH THIS VIDEO:

https://youtu.be/b3GD8263-PQ?si=cYhOut9cFwWYmzkh

This alternate way of solving means we just simply use the techniqe of finding the number of partitions with given difference


*/



int solveRecMem(vector<int>& nums, int& target, int& BIGVALUE, int index, int currentSum, vector<vector<int>>& dp){

        // base cases
        if(index >= nums.size()){

            if(currentSum == target + BIGVALUE){     // we are checking if currentSum is equal to target + that BIGVALUE that we had set it to initially. That was the initial value and we are considering that as the 0th value. And from there we want to reach target.
                return 1;
            }
            else {
                return 0;
            }
        }


        // check in dp
        if(dp[index][currentSum] != -1) return dp[index][currentSum];


        // possibilities
        int plus = solveRecMem(nums, target, BIGVALUE, index + 1, currentSum + nums[index], dp);
        int minus = solveRecMem(nums, target, BIGVALUE, index + 1, currentSum - nums[index], dp);


        // populate in dp
        return dp[index][currentSum] = plus + minus;
}


int targetSum(int n, int target, vector<int>& nums) {
    // Write your code here.

        int totalSum = 0;
        for(int i : nums){
            totalSum += i;
        }

        int BIGVALUE = totalSum + 5000;

        int currentSum = BIGVALUE;       // we keep the currentSum to some big value so that even if we do all minuses on all numbers, still currentSum will not be negative and we dont want currentSum to be negative because if it is negative then the dp will try to access a negative index which will throw errors
        int colSize = currentSum + totalSum + 1;    // we want the colsize to be even bigger than currentSum because when we do all pluses, then currentSum will go out of bounds and this can also thrrow error

        vector<vector<int>> dp(nums.size()+1, vector<int>(colSize, -1));
        return solveRecMem(nums, target, BIGVALUE, 0, currentSum, dp);

}




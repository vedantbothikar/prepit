#include <bits/stdc++.h>


/*

We want to find if there exists a partition so that we get 2 arrays of equal sum


We want to find all possibilities so recursion
	- We have overlapping sub problems so DP


So, if we want to find 2 subarrays of equal sum, then then that means:
- Each subarrays has equal sum (partSum)
- So the total sum of full array is 2*partSum

Which means, we just have to find that:
- IF THERE EXISTS A SUBARRAY WHOSE SUM IS EQUAL TO PARTSUM
Which also means that this is similar to the previous question of finding:
- FIND IF THERE EXISTS A SUBSET WHOSE SUM IS EQUAL TO A TARGET K
	- https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954




*/



bool solveRecMem(vector<int> &arr, int n, int index, int target, vector<vector<int>>& dp){

	// base cases
	if(target == 0){
		return true;
	}

	if(index >= n){
		return false;
	}

	if(target < 0){
		return false;
	}


	// check in dp
	if(dp[index][target] != -1){
		return dp[index][target];
	}


	// possibilities
	bool include = solveRecMem(arr, n, index+1, target-arr[index], dp);
	bool exclude = solveRecMem(arr, n, index+1, target, dp);



	// populate in dp
	return dp[index][target] = include or exclude;
}


bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.

	// find the sum of all elements in the vector
	int totalSum = 0;
	for(int i : arr){
		totalSum += i;
	}

	// Check if totalSum is odd
	// If it is odd, then it can't be broken into 2 equal integers, so we can't have 2 equal partitions
	if(totalSum % 2 == 1){
		return false;
	}

	int partSum = totalSum / 2;
	// Declare dp of size n*partSum+1 
	vector<vector<int>> dp(n+1, vector<int>(partSum+1, -1));


	return solveRecMem(arr, n, 0, partSum, dp);
}


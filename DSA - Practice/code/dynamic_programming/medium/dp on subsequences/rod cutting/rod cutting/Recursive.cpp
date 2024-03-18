#include<bits/stdc++.h>
using namespace std;



/*

https://www.codingninjas.com/studio/problems/rod-cutting-problem_800284

Same as unbounded knapsack where you need to maximize the profit

*/

int solveRecMem(vector<int>& price, int n, int index, int cuts, vector<vector<int>>& dp){

	// base cases
	if(index > n) return 0;		// we are checking > n and not >= n because of 1-based indexing

	if(cuts == 0) return 0;


	// check in dp
	if(dp[index][cuts] != -1) return dp[index][cuts];


	// possibilities
	int include = 0;
	if(cuts >= index){
		// we are taking index-1 because we are already 1-indexed
		include = price[index-1] + solveRecMem(price, n, index, cuts-index, dp);
	}
	int exclude = solveRecMem(price, n, index+1, cuts, dp);


	// populate in dp
	return dp[index][cuts] = max(include, exclude);
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

	// we are starting index from 1 because we are asked so in the question
	return solveRecMem(price, n, 1, n, dp);
}



int main () {


    return 0;
}
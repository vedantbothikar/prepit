#include<bits/stdc++.h>
using namespace std;


int solveRecMem(vector<int>& weight, vector<int>& value, int& n, int targetWeight, int index, vector<vector<int>>& dp){

	// base cases
	if(index >= n){
		return 0;
	}

	if(targetWeight == 0){
		return 0;
	}

	// check in dp
	if(dp[index][targetWeight] != -1){
		return dp[index][targetWeight];
	}


	// explore all possibilities
	int include = 0;
	if(targetWeight - weight[index] >= 0){
		include = value[index] + solveRecMem(weight, value, n, targetWeight - weight[index], index+1, dp); 
	}
	
	int exclude = solveRecMem(weight, value, n, targetWeight, index+1, dp);


	// populate in dp
	return dp[index][targetWeight] = max(include, exclude);
}


int knapsack(vector<int> weight, vector<int> value, int n, int targetWeight) 
{
	// Write your code here

	int totalValue = 0;
	for(int i : value){
		totalValue += i;
	}

	vector<vector<int>> dp(n+1, vector<int>(targetWeight+1, -1));

	return solveRecMem(weight, value, n, targetWeight, 0, dp);
}

int main () {


    return 0;
}
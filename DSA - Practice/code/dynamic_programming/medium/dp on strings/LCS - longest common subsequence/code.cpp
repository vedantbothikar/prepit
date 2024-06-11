#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
/*


BASE CASES:
- Whenever any length goes to less than 0
	- Then return 


*/




int solveRecMem(string& s, string& t, int m, int n, vector<vector<int>>& dp){

	// base cases
	if(m < 0 or n < 0){
		return 0;
	}


	// check in dp
	if(dp[m][n] != -1){
		return dp[m][n];
	}


	// possibilities
	int lcs = 0;

	// if current elements match
	if(s[m] == t[n]){

		lcs = 1 + solveRecMem(s, t, m-1, n-1, dp);
	}
	else{

		int reduceFirst = solveRecMem(s, t, m-1, n, dp);
		int reduceSecond = solveRecMem(s, t, m, n-1, dp);
		lcs = max(reduceFirst, reduceSecond);
	}



	// populate in dp
	return dp[m][n] = lcs;
}


int lcs(string s, string t)
{
	//Write your code here
	int m = s.length();
	int n = t.length();

	vector<vector<int>> dp(m, vector<int>(n, -1));	

	return solveRecMem(s, t, m-1, n-1, dp);
}
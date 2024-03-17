
/*


https://www.codingninjas.com/studio/problems/count-subsets-with-sum-k_3952532


include, exclude technique
if sum == target
	THEN: stop and return 1 as count

if index out of bounds:
	THEN: return 0


dp[index][target] = include + exclude

*/


int zeroCount = 0;

int solveRecMem(vector<int>& arr, int target, int n, int index, vector<vector<int>>& dp){

	// base cases

	// if arr[i] == 0 we can include it even if we reached our target

	if(target == 0){
		return 1 + pow(2, zeroCount)-1;
	}

	if(index >= n){
		return 0;
	}

	if(target  < 0){
		return 0;
	}

	// check in dp
	if(dp[index][target] != -1){
		return dp[index][target];
	}

	// possibilities
	int include = solveRecMem(arr, target-arr[index], n, index+1, dp) % 1000000007;
	int exclude = solveRecMem(arr, target, n, index+1, dp) % 1000000007;


	// populate in dp
	return dp[index][target] = (include + exclude) % 1000000007;
}

int findWays(vector<int>& arr, int k)
{
	// Write your code here.

	int n = arr.size();
	vector<vector<int>> dp(n+1, vector<int>(k+1, -1));

	// loop through all elements and check how many zeroes are there
	for(int i : arr){
		if (i == 0) zeroCount++;	// zeroCount is a global variable
	}
	
	return solveRecMem(arr, k, n, 0, dp);
}

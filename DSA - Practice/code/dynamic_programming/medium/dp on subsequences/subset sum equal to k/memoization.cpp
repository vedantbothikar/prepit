#include <bits/stdc++.h>
using namespace std;


/*

Watch this video: https://youtu.be/fWX9xDmIzRI?si=45HqS_psT-kJArzl
This will explain how to work with questions on subsequences


*/

bool solveRecMem(int index, int target, vector<int>& arr, vector<vector<int>>& dp){

    // basecases
    if(target == 0){
        return true;
    }

    if(index < 0){
        return false;
    }

    if(target < 0){
        return false;
    }

    // check in dp
    if(dp[index][target] != -1){
        return dp[index][target];
    }


    // check all possibilities
    bool include = solveRecMem(index-1, target-arr[index], arr, dp);
    bool exclude = solveRecMem(index-1, target, arr, dp);

    // populate in dp
    return dp[index][target] = include or exclude;
}



bool subsetSumToK(int n, int target, vector<int> &arr) {
    // Write your code here.

    vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
    return solveRecMem(n-1, target, arr, dp);
}
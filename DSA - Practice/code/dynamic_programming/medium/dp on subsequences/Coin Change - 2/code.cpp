#include<bits/stdc++.h>
using namespace std;


/*

Problem statement
You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make a change for value V using coins of denominations from D. Print 0, if a change isn't possible.



*/

/*

https://www.codingninjas.com/studio/problems/ways-to-make-coin-change_630471
Count the number of ways you can make the target


*/



long solve(int* denominations, int n, int target, vector<vector<long>>& dp, int index) {

    // base case
    if (target == 0) {
        return 1;
    }

    if (index >= n) {
        return 0;
    }

    if (target < 0) {
        return 0;
    }

    // check in dp
    if (dp[index][target] != -1) {
        return dp[index][target];
    }

    // possibilities
    long include = solve(denominations, n, target - denominations[index], dp, index);
    long exclude = solve(denominations, n, target, dp, index + 1);

    // populate in dp
    return dp[index][target] = include + exclude;
}



long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here

    vector<vector<long>> dp(n+1, vector<long>(value+1, -1));

    return solve(denominations, n, value, dp, 0);
}












int main () {


    return 0;
}
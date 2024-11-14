#include<bits/stdc++.h>
using namespace std;
/*

https://leetcode.com/problems/minimum-path-sum/description/
https://www.codingninjas.com/studio/problems/minimum-path-sum_985349
https://www.youtube.com/watch?v=_rgTlyky1uQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=11


RECURSION:
- go through all paths and check the cost
- DP: overlapping sub problems


*/

int solveRecMem(vector<vector<int>> &grid, int n, int m, int rows, int cols, vector<vector<int>> &dp){

    // base cases
    // if rows and cols reach destination
    if(rows == n-1 and cols == m-1){
        return grid[rows][cols];
    }

    // if rows or cols reach end of grid and can't move further in that direction
    if(rows > n-1 or cols > m-1){
        return 1e9;
    }


    // check in dp
    if(dp[rows][cols] != -1){
        return dp[rows][cols];
    }


    // try all possibilities
    int right = grid[rows][cols] + solveRecMem(grid, n, m, rows, cols+1, dp);
    int down = grid[rows][cols] + solveRecMem(grid, n, m, rows+1, cols, dp);


    // populate dp
    return dp[rows][cols] = min(right, down);
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.

    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    return solveRecMem(grid, n, m, 0, 0, dp);
}

int main () {


    return 0;
}
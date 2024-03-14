#include<bits/stdc++.h>
using namespace std;

/*
https://www.codingninjas.com/studio/problems/maze-obstacles_977241

*/

int solveRecMem(int n, int m, vector<vector<int>> &mat, int row, int col, vector<vector<int>>& dp){


    // base cases
    if(row == n-1 and col == m-1){
        return 1;
    }

    if(row > n-1){
        return 0;
    }

    if(col > m-1){
        return 0;
    }
    
    if(row <= n-1 and col <= m-1 and mat[row][col] == -1){
        return 0;
    }


    // check in dp
    if(dp[row][col] != -1){
        return dp[row][col];
    }


    // possibilities
    int down = solveRecMem(n, m, mat, row+1, col, dp) % 1000000007;
    int right = solveRecMem(n, m, mat, row, col+1, dp) % 1000000007;



    // populate in dp and return
    return dp[row][col] = (down + right) % 1000000007;

}




int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here

    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return solveRecMem(n, m, mat, 0, 0, dp);
}

int main () {


    return 0;
}
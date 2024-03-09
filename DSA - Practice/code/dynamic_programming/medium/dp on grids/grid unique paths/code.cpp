#include <bits/stdc++.h>
using namespace std;

/*

Problem:
https://leetcode.com/problems/unique-paths/


Solution:
https://www.youtube.com/watch?v=sdE0A2Oxofw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=9



*/

class Solution
{
public:
    /*

    m: rows
    n: columns

    TODOs:
    - find the base case
    - when go right or down: what will change in indices?


    possibilities:
    - go right
    - go down


    When go right:
    - m, n+1


    When go down:
    - m+1, n

    General:
    - create a 2D dp vector of m x n


    base cases:
    - when indices hit max
    - when target is reached

    target:
    - rows == n-1 && cols == m-1

    indices hit max:
    - rows == m-1
    - cols == n-1




    */

    int solveRecMem(int m, int n, int rows, int cols, vector<vector<int>> &dp)
    {

        // base cases
        if (rows == m - 1 && cols == n - 1)
        {
            return 1;
        }

        if (rows >= m)
        {
            return 0;
        }
        if (cols >= n)
        {
            return 0;
        }

        // check in dp
        if (dp[rows][cols] != -1)
        {
            return dp[rows][cols];
        }

        // possibilities
        int right = solveRecMem(m, n, rows, cols + 1, dp);
        int down = solveRecMem(m, n, rows + 1, cols, dp);

        // populate in dp
        return dp[rows][cols] = right + down;
    }

    int uniquePaths(int m, int n)
    {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solveRecMem(m, n, 0, 0, dp);
    }
};

int main()
{

    return 0;
}
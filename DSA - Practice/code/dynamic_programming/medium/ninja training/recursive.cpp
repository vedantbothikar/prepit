#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

/*

Let's consider the 3 activities as 3 numbers
0,1,2


Problem: https://www.codingninjas.com/studio/problems/ninja%E2%80%99s-training_3621003
SOlution: https://www.youtube.com/watch?v=AE39gJYuRog&embeds_referring_euri=https%3A%2F%2Ftakeuforward.org%2F&source_ve_path=OTY3MTQ&feature=emb_imp_woyt



*/

// n indicates the day

int solveRecMem(int n, vector<vector<int>> &points, vector<vector<int>> &dp, int lastActivity)
{

    // base case
    if (n < 0)
    {
        // return maxPointsForDay0ConsideringLastActivity(points, dp, lastActivity);

        return 0;
    }

    // check in dp
    if (dp[n][lastActivity] != -1)
    {
        return dp[n][lastActivity];
    }

    int maxPoints = 0;
    // possibilities
    for (int activity = 0; activity < 3; activity++)
    {

        if (activity != lastActivity)
        {

            int currentPoints = points[n][activity] + solveRecMem(n - 1, points, dp, activity);
            maxPoints = max(maxPoints, currentPoints);
        }
    }

    // populate in dp
    return dp[n][lastActivity] = maxPoints;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.

    // declare a 2D vector of size n x 3 and initialize that to -1
    vector<vector<int>> dp(n, vector<int>(4, -1));

    // pass n-1 instead of n because we are starting training from Day 1 and not Day 0
    return solveRecMem(n - 1, points, dp, 3);
}

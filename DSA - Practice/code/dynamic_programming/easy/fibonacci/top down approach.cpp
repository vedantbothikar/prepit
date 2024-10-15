#include <bits/stdc++.h>
using namespace std;

/*

top down approach
recursive


Here
TC O(N) - because we are traversing all elements till n only once
SC 2O(N) - because we are storing the values in dp array, this will take O(N) and
            we are using a recursive approach... so this recursive stack will take another O(N)
*/

int fib(int n, vector<int> &dp)
{

        // base case
        if (n == 0)
        {
                return 0;
        }
        if (n == 1)
        {
                return 1;
        }

        // check if value present in dp
        if (dp[n] != -1)
        {
                return dp[n];
        }

        dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
        return dp[n];
}

int main()
{
        /*
         *  Write your code here.
         *  Read input as specified in the question.
         *  Print output as specified in the question.
         */

        int n;
        cin >> n;

        // initialize dp vector
        vector<int> dp(n + 1);

        for (int i = 0; i <= n; i++)
        {
                dp[i] = -1;
        }

        cout << fib(n, dp);

        return 0;
}
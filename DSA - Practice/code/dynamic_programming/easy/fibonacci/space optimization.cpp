#include <bits/stdc++.h>
using namespace std;

/*

BEST SOLUTION

TC O(N) - going through all numbers only once
SC O(1)  - we are only using variables



*/

int main()
{
    /*
     *  Write your code here.
     *  Read input as specified in the question.
     *  Print output as specified in the question.
     */

    // space optimization using variables
    // use variables prev1 and prev2

    int n;
    cin >> n;

    int prev1 = 0, prev2 = 1;

    vector<int> dp(n + 1);
    dp[0] = prev1;
    dp[1] = prev2;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = prev1 + prev2;

        // swap
        prev1 = prev2;
        prev2 = dp[i];
    }

    cout << dp[n];

    return 0;
}
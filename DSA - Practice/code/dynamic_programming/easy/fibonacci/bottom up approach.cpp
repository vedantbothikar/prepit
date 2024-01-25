#include <bits/stdc++.h>
using namespace std;

/*

using for loop


Here
TC O(N) - because we are traversing all elements till n only once
SC O(N) - because we are storing the values in dp array, this will take O(N)

NOTE: in terms of space, this approach is better than top down approach because there space was 2*O(N)
but that will not cause a big problem

still this is slightly better than it


*/

int main()
{
    /*
     *  Write your code here.
     *  Read input as specified in the question.
     *  Print output as specified in the question.
     */

    /*
    Bottom up apprach - for loop
    */

    int n;
    cin >> n;

    vector<int> dp(n + 1);

    dp[0] = 0;
    dp[1] = 1;

    // populate the dp array first
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n];

    return 0;
}
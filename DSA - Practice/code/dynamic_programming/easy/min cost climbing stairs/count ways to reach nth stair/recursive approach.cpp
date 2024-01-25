#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

/*
THIS IS RECURSIVE APPROACH

- this will give TLE because there are overlapping subproblems

*/

void solve(int n, int &ans)
{

    // base case
    if (n == 0 or n == 1)
    {
        ans++;
        return;
    }

    // take 1 step
    solve(n - 1, ans);

    // take 2 steps
    solve(n - 2, ans);
}

int countDistinctWays(int nStairs)
{
    //  Write your code here.

    int ans = 0;

    solve(nStairs, ans);

    return ans % MOD;
}
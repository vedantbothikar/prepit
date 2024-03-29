#include <bits/stdc++.h>
using namespace std;

/*

BEST SOLUTION

TC O(N) - going through all numbers only once
SC O(1)  - we are only using variables

*/

class Solution
{
public:
    int fib(int n)
    {

        if (n == 0 or n == 1)
            return n;

        int prev1 = 0, prev2 = 1;
        int curr = 0;

        for (int i = 2; i <= n; i++)
        {
            curr = prev1 + prev2;

            // swap
            prev1 = prev2;
            prev2 = curr;
        }

        return curr;
    }
};
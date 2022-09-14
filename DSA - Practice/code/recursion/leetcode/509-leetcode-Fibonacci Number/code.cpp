#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{

    // base cases
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    // cases when we have use previous two calculations

    int ans = fib(n - 1) + fib(n - 2);
    return ans;
}

int main()
{

    return 0;
}
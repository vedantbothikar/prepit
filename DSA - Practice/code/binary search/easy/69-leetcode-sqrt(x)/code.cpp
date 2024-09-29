#include <bits/stdc++.h>
using namespace std;

// EASY TO UNDERSTAND SOLUTION

int mySqrt(int x)
{

    int start = 0, end = x / 2;
    long long mid = start + (end - start) / 2;
    int ans = mid;

    // handle when single element
    if (x == 0 || x == 1)
    {
        return x;
    }

    while (start <= end)
    {

        if (mid * mid == x)
        {
            return mid;
        }
        else if (mid * mid > x)
        {
            end = mid - 1;
        }
        else if (mid * mid < x)
        {
            ans = mid;  // IMPORTANT STEP
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }

    return ans;
}

int main()
{

    return 0;
}
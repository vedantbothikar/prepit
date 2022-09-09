#include <bits/stdc++.h>
using namespace std;

// little bit COMPLEX Solution

int mySqrt(int x)
{

    int start = 0, end = x / 2;
    long long mid = start + (end - start) / 2;
    int last = x / 2;

    // handle when single element
    if (x == 0 || x == 1)
    {
        return x;
    }

    while (start <= end)
    {

        if (mid == 0)
        {
            if ((mid + 1) * (mid + 1) > x)
            {
                return mid;
            }
            else
            {
                start = mid + 1;
            }
        }
        else if (mid == last)
        {
            if ((mid - 1) * (mid - 1) < x)
            {
                return mid;
            }
            else
            {
                end = mid - 1;
            }
        }
        else
        {

            if ((mid * mid == x) || ((mid - 1) * (mid - 1) < x && (mid + 1) * (mid + 1) > x && (mid * mid < x)))
            {
                return mid;
            }
            else if (mid * mid > x)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        mid = start + (end - start) / 2;
    }

    return mid;
}

int main()
{

    return 0;
}
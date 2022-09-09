// WE are finding the square root with
// decimal numbers upto a certain precision here

#include <bits/stdc++.h>
using namespace std;

// this function will return the integer part of the
// square root
int mySqrt(int x)
{

    int start = 0, end = x / 2;
    long long mid = start + (end - start) / 2;
    int last = x / 2;
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
            ans = mid;
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }

    return ans;
}

// n is the number of which sqrt is to be found
// x is the integer part of the sqrt
double morePrecision(int n, int x, int precision)
{

    double factor = 1;
    double ans = x;

    for (int i = 0; i < precision; i++)
    {

        factor = factor / 10;

        while ((ans + factor) * (ans + factor) < n)
        {
            ans = ans + factor;
        }
    }

    return ans;
}

int main()
{

    int n;
    cout << "enter the number you want to find square root of: " << endl;
    cin >> n;

    int intSqrt = mySqrt(n);

    cout << "ANSWER IS: " << morePrecision(n, intSqrt, 3) << endl;

    return 0;
}
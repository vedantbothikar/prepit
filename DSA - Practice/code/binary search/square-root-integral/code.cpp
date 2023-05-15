#include <bits/stdc++.h>
using namespace std;

#include <iostream>
using namespace std;

/*

https://www.codingninjas.com/codestudio/problems/square-root-integral_624660

NORMAL APPROACH is to have a loop and check if the square of the number is equal to the number or not.

Efficient approach is
binary search:

start = 0
end = N/2

apply binary search in this range



*/

int binSearchRoot(long long int n)
{

    long long int start = 0;
    long long int end = n / 2;

    long long int ans = 0;

    while (start <= end)
    {

        long long int mid = start + (end - start) / 2;

        long long int sqr = mid * mid;

        if (sqr == n)
        {
            return mid;
        }

        else if (sqr > n)
        {
            end = mid - 1;
        }
        else
        {
            ans = mid;
            start = mid + 1;
        }
    }

    return ans;
}

int main()
{
    // Write your code here

    long long int n;
    cin >> n;

    cout << binSearchRoot(n);
}

int main()
{

    return 0;
}
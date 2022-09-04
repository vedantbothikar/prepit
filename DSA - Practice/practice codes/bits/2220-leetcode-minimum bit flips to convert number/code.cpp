#include <bits/stdc++.h>
using namespace std;

int minBitFlips(int start, int goal)
{

    int n = start ^ goal;

    int count = 0;

    // count number of set bits
    while (n != 0)
    {

        if (n & 1)
        {
            count++;
        }

        n = n >> 1;
    }

    return count;
}

int main()
{

    cout << minBitFlips(10, 7);

    return 0;
}
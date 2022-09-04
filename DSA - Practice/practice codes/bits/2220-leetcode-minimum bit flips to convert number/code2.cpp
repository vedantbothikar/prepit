#include <bits/stdc++.h>
using namespace std;

int minBitFlips(int start, int goal)
{

    int count = 0;

    // counting bits that are same in both numbers
    for (int i = 0; i < 32; i++)
    {

        if ((start & 1) && (goal & 1))
        {
            count++;
        }
        else if (!(start & 1) && !(goal & 1))
        {
            count++;
        }

        start = start >> 1;
        goal = goal >> 1;
    }

    // returning bits that are not same
    return 32 - count;
}

int main()
{

    cout << minBitFlips(10, 7);

    return 0;
}
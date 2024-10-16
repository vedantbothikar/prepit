/*

- https://leetcode.com/problems/find-pivot-index/description/
*/

#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int> &nums)
{

    vector<int> sum;

    // store all sums
    sum.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
        sum.push_back(sum[i - 1] + nums[i]);
    }

    int size = nums.size();
    int last = size - 1;
    int sum1, sum2;
    int ans = -1;

    // check one by one if sums are equal
    for (int i = 0; i < size; i++)
    {

        if (i > 0)
        {
            sum1 = sum[i - 1];
            sum2 = sum[last] - sum[i];
        }
        else
        {
            sum1 = 0;
            sum2 = sum[last] - sum[i];
        }

        if (sum1 == sum2)
        {
            return i;
        }
    }

    return ans;
}

int main()
{

    return 0;
}
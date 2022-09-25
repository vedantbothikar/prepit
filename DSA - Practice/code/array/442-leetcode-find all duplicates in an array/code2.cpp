#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int> &nums)
{

    unordered_map<int, int> m;

    // store the count of all nums in the map
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]]++;
    }

    vector<int> ans;
    // traverse m and check if any count in greater than 1
    for (auto i : m)
    {
        if (i.second > 1)
        {
            ans.push_back(i.first);
        }
    }

    return ans;
}
#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int> &nums)
{
    //sort the array
    sort(nums.begin(), nums.end());

    vector<int> dups;

    // check if the next element is duplicate
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            dups.push_back(nums[i]);
        }
    }

    return dups;
}

int main()
{

    vector<int> arr;
    vector<int> dups;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int inp;
        cin >> inp;
        arr.push_back(inp);
    }

    dups = findDuplicates(arr);

    for (int i = 0; i < dups.size(); i++)
    {
        /* code */
        cout << dups[i] << " ";
    }

    return 0;
}
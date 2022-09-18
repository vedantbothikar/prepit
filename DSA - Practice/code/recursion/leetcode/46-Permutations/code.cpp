#include <bits/stdc++.h>
using namespace std;

// every index is to be swaped by every next element
// recursion for index
// loop for swapping every next element

void printvec(vector<int> &output)
{

    for (auto i : output)
    {
        cout << i << " ";
    }

    cout << endl;
}

void solve(vector<int> nums, int index, vector<vector<int>> &ans)
{

    // base case
    if (index >= nums.size())
    {
        cout << "base case hit" << endl;
        ans.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {
        // swap every next element with index element

        cout << "i: " << i << " index: " << index << endl;

        cout << "nums before swap: ";
        printvec(nums);

        swap(nums[index], nums[i]);

        cout << "nums after swap: ";
        printvec(nums);

        solve(nums, index + 1, ans);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{

    vector<int> output;
    vector<vector<int>> ans;
    int index = 0;

    solve(nums, index, ans);

    return ans;
}

int main()
{

    return 0;
}
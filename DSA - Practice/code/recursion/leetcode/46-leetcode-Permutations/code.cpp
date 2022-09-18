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

        swap(nums[index], nums[i]);

        solve(nums, index + 1, ans);

        // backtrack
        swap(nums[index], nums[i]);
        // (to make sure that the variable is not a tampered one for the next iteration)
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
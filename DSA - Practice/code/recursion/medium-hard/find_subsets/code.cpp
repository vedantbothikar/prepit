#include <bits/stdc++.h>
using namespace std;

/*

https://www.codingninjas.com/codestudio/problems/find-all-subsets_2041970

*/

void solve(vector<int> subans, vector<vector<int>> &ans, vector<int> arr, int index)
{
    // Write your code here

    // base case
    if (index >= arr.size())
    {

        // add only if subans is not empty
        if (!subans.empty())
        {
            ans.push_back(subans);
        }

        return;
    }

    // exclude
    solve(subans, ans, arr, index + 1);

    // include
    subans.push_back(arr[index]);
    solve(subans, ans, arr, index + 1);
}

vector<vector<int>> FindAllSubsets(int n, vector<int> &arr)
{
    // Write your code here

    // Handle empty vector

    vector<vector<int>> ans;
    vector<int> subans;
    int index = 0;

    solve(subans, ans, arr, index);
    return ans;
}

int main()
{

    return 0;
}
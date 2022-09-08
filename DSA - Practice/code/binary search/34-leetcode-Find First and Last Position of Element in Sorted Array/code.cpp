#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{

    vector<int> ans;
    ans.push_back(INT_MAX);
    ans.push_back(INT_MIN);

    int start = 0, end = nums.size() - 1;
    int mid = start + (end - start) / 2;

    // for first occurrence
    while (start <= end)
    {

        if (nums[mid] == target)
        {

            // first occurrence
            if (ans[0] > mid)
            {
                ans[0] = mid;
            }

            end = mid - 1;
        }

        else if (nums[mid] > target)
        {
            end = mid - 1;
        }
        else if (nums[mid] < target)
        {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }

    // initializations
    start = 0, end = nums.size() - 1;
    mid = start + (end - start) / 2;

    // for last occurrence
    while (start <= end)
    {

        if (nums[mid] == target)
        {

            // last occurrence
            if (ans[1] < mid)
            {
                ans[1] = mid;
            }

            start = mid + 1;
        }

        else if (nums[mid] > target)
        {
            end = mid - 1;
        }
        else if (nums[mid] < target)
        {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }

    // if we didn't get any solution
    if (ans[0] == INT_MAX)
    {
        ans[0] = -1;
    }
    if (ans[1] == INT_MIN)
    {
        ans[1] = -1;
    }

    cout << "NUMBER OF OCCURRENCES:" << ans[1] - ans[0] + 1 << endl;

    return ans;
}

int main()
{

    vector<int> arr;
    int n;
    cin >> n;
    int inp;
    for (int i = 0; i < n; i++)
    {
        cin >> inp;
        arr.push_back(inp);
    }

    int target;
    cout << "Enter target to find: ";
    cin >> target;

    vector<int> res = searchRange(arr, target);

    for (int i = 0; i < 2; i++)
    {
        cout << res[i] << " ";
    }

    cout << endl;

    return 0;
}
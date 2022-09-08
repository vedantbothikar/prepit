#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int> &nums)
{

    int size = nums.size();
    int ans = -1;
    int last = size - 1;

    int start = 0, end = size - 1, mid = start + (end - start) / 2;

    while (start <= end)
    {

        // handling cases when we reach ends
        if (mid == 0)
        {
            // handling case when the array is rotated 0 times (the array is not at all rotated)
            if (nums[mid] < nums[mid + 1])
            {
                return nums[mid];
            }
            else
            {
                start = mid + 1;
            }
        }
        else if (mid == size - 1)
        {

            // handling case when the array is entirely rotated (descending order)
            if (nums[mid] < nums[mid - 1])
            {
                return nums[mid];
            }
            else
            {
                end = mid - 1;
            }
        }
        else
        {
            if (nums[mid] < nums[mid + 1] && nums[mid - 1] > nums[mid])
            {
                return nums[mid];
            }
            else if (nums[mid] <= nums[last])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        mid = start + (end - start) / 2;
    }

    return ans;
}

int main()
{

    int n;
    cin >> n;

    vector<int> arr;
    int inp;

    for (int i = 0; i < n; i++)
    {

        cin >> inp;
        arr.push_back(inp);
    }

    cout << pivotIndex(arr);

    return 0;
}
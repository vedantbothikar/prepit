#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int> &nums)
{

    int size = nums.size();

    int start = 0, end = size - 1, mid = start + (end - start) / 2;

    while (start <= end)
    {

        if (nums[mid] > nums[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }

        mid = start + (end - start) / 2;
    }

    return start;
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
#include <bits/stdc++.h>
using namespace std;

// FOR PIVOT INDEX- REFER TO 153-LEETCODE-MINIMUM IN ROTATED SORTED ARRAY
int pivotIndex(vector<int> &nums)
{

    // handle case when there is only 1 element
    if (nums.size() == 1)
    {
        return 0;
    }

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
                return mid;
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
                return mid;
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
                return mid;
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

int binarysearch(vector<int> &nums, int start, int end, int target)
{

    int mid = start + (end - start) / 2;

    while (start <= end)
    {

        if (nums[mid] == target)
        {

            return mid;
        }
        else if (nums[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }

    return -1;
}

// handle
// single element
// two elements
// 3,5,1
int search(vector<int> &nums, int target)
{

    int pi = pivotIndex(nums);

    int size = nums.size();
    int start = 0, end = 0, mid = start + (end - start) / 2;

    // deciding whether to start searching in first or second part of the array

    if (target <= nums[size - 1])
    {
        // second part
        start = pi;
        end = size - 1;
    }
    else
    {
        // first part
        start = 0;
        end = pi - 1;
    }

    mid = start + (end - start) / 2;

    int ans = binarysearch(nums, start, end, target);

    return ans;
}

int main()
{

    return 0;
}
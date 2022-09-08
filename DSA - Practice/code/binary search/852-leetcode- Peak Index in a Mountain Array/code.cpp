#include <bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{

    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2;
    int ans = 0;

    while (start <= end)
    {

        if (mid == 0)
        {
            start = mid + 1;
        }
        else if (mid == arr.size() - 1)
        {
            end = mid - 1;
        }
        else
        {
            if ((arr[mid] > arr[mid + 1]) && (arr[mid] > arr[mid - 1]))
            {
                ans = mid;
                return ans;
            }

            else if ((arr[mid] > arr[mid - 1]))
            {
                start = mid + 1;
            }

            else if ((arr[mid] > arr[mid + 1]))
            {
                end = mid - 1;
            }
        }

        mid = start + (end - start) / 2;
    }

    return ans;
}

int main()
{

    return 0;
}
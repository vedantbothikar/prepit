#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int arr[], int start, int end, int target)
{

    if (start > end)
    {

        cout << "start > end" << endl;
        return false;
    }

    int mid = start + (end - start) / 2;

    cout << "Start: " << start << endl;
    cout << "End: " << end << endl;
    cout << "Mid: " << mid << endl;

    cout << "arr[mid]: " << arr[mid] << " target: " << target << endl;

    if (arr[mid] == target)
    {
        return true;
    }

    if (arr[mid] > target)
    {
        cout << "arr[mid] > target" << endl;

        binarySearch(arr, start, mid - 1, target);
    }
    else if (arr[mid] < target)
    {
        cout << "arr[mid] < target" << endl;
        binarySearch(arr, mid + 1, end, target);
    }
}

int main()
{

    int arr[5] = {2, 4, 6, 8, 10};
    cout << binarySearch(arr, 0, 4, 7) << endl;

    return 0;
}
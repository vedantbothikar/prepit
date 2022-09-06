#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr)
{
    // XOR all elements of the array with 1,2,3,...N-1
    // by doing this only the duplicate element will be left in ans

    int ans = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        ans = ans ^ arr[i];
    }

    for (int i = 0; i < arr.size(); i++)
    {
        ans = ans ^ i;
    }

    return ans;
}

int main()
{

    vector<int> arr;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int inp;
        cin >> inp;
        arr.push_back(inp);
    }

    cout << findDuplicate(arr);

    return 0;
}
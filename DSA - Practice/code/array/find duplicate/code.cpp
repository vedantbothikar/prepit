#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr)
{
    // Write your code here

    int n = arr.size();

    // find expected sum
    int exsum = (n * (n + 1)) / 2;

    // find actual sum
    int acsum = 0;
    for (int i = 0; i < n; i++)
    {
        acsum += arr[i];
    }

    return n - (exsum - acsum);
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
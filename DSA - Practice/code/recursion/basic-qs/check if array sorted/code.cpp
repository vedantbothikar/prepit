#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> arr, int n)
{
    if (n < 1)
    {
        return 1;
    }

    if (arr[n - 2] > arr[n - 1])
    {
        cout << "inside" << endl;
        return 0;
    }

    bool ans = isSorted(arr, n - 1);

    return ans;
}

int main()
{

    vector<int> arr = {1};

    cout << "Answer: " << endl;
    cout << isSorted(arr, arr.size()) << endl;

    return 0;
}
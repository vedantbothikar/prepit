#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;

    // push -1 so that this will be the smallest element
    s.push(-1);

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {

        while (s.top() >= arr[i])
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(arr[i]);
    }

    return ans;
}

int main()
{

    return 0;
}
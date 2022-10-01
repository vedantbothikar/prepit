#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>> &m, int n)
{
    // code here

    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    while (s.size() > 1)
    {

        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        // check if a knows b => a not celebrity
        if (m[a][b] == 1)
        {
            s.push(b);
        }
        // b knows a => b not celebrity
        else
        {
            s.push(a);
        }
    }

    // single element will be present in the stack now
    // check if it is a solution

    int ans = s.top();

    // CHECK if all row values are equal to 0
    for (int i = 0; i < n; i++)
    {
        if (m[ans][i] == 1)
        {
            return -1;
        }
    }

    // CHECK if all the column values except their own is equal to 1
    for (int i = 0; i < n; i++)
    {
        if (i == ans)
        {
            continue;
        }

        if (m[i][ans] == 0)
        {
            return -1;
        }
    }

    return ans;
}

int main()
{

    return 0;
}
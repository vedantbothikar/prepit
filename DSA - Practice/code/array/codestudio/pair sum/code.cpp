#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    // Write your code here.

    int i = 0, j = 1;

    vector<vector<int>> ans;
    vector<int> temp;
    bool gotit = 0;

        for (int i = 0; i < arr.size(); i++)
    {

        for (int j = i + 1; j < arr.size(); j++)
        {

            if (arr[i] + arr[j] == s)
            {

                // pushing minimum first then max (as per qs)
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                ans.push_back(temp);
                temp.clear();
            }
        }
    }

    // sorting is required because it is asked in the question
    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{

    return 0;
}
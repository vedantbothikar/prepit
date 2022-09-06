#include <bits/stdc++.h>
using namespace std;

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    // Write your code here.

    vector<int> res;
    int j = 0, i = 0;

    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            res.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
    }

    return res;
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE
// O(N*M)

// TLE error

// keep checking every element of arr1 with other element of arr2
// whenever they are equal, push into res vector

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    // Write your code here.

    vector<int> res;

    for (int i = 0; i < n; i++)
    {

        int start = 0;
        for (int j = start; j < m; j++)
        {
            if (arr1[i] == arr2[j])
            {
                arr2[j] = INT_MIN;
                res.push_back(arr1[i]);
                start = j + 1;
                break;
            }
            else if (arr2[j] > arr1[i])
            {
                break;
            }
        }
    }
}

int main()
{

    return 0;
}
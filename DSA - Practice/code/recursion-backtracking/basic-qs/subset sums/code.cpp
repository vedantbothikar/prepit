#include <bits/stdc++.h>
using namespace std;

/*

- https://practice.geeksforgeeks.org/problems/subset-sums2234/1

*/

/*

Print sum of all subsets

- we need to be able to find all possible subsets

// exclude
// include




*/

class Solution
{

private:
    void listAllSubsets(vector<int> arr, int count, int currentsum, vector<int> &ans)
    {

        // base case
        if (count >= arr.size())
        {
            ans.push_back(currentsum);
            return;
        }

        // exclude
        listAllSubsets(arr, count + 1, currentsum, ans);

        // include
        currentsum += arr[count];
        listAllSubsets(arr, count + 1, currentsum, ans);
    }

public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here

        int currentsum = 0;
        int count = 0;
        vector<int> ans;

        listAllSubsets(arr, count, currentsum, ans);
        return ans;
    }
};

int main()
{

    return 0;
}
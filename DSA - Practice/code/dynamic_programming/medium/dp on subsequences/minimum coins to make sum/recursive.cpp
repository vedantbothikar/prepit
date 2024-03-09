#include <bits/stdc++.h>
using namespace std;

// TLE for bigger test cases

/*
RECURSIVE SOLUTION

base case
if sum becomes 0, then choose the min of the ans
if sum becomes negative, then abort - make ans as INT_MAX and choose the min

for every element of the vector, try reducing it and calling the function once again


*/
void solveRec(vector<int> &num, int target, int count, int &ans)
{

    // base case
    if (target == 0)
    {
        ans = min(ans, count);
        return;
    }

    if (target < 0)
    {
        return;
    }

    // check for every element of the vector
    for (int i = 0; i < num.size(); i++)
    {
        solveRec(num, target - num[i], count + 1, ans);
    }
}

int main()
{

    return 0;
}
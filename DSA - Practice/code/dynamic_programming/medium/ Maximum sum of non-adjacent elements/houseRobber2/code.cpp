#include <bits/stdc++.h>

/*

code problem:
https://www.codingninjas.com/studio/problems/house-robber_839733
https://leetcode.com/problems/house-robber-ii/

solution:
https://www.youtube.com/watch?v=Fe2GeXEzWM0&list=PLDzeHZWIZsTomOPnCiU3J95WufjE36wsb&index=5

*/

/*


 explanation:


 so we can either use first element or last element


so when we use first, we cant use last
and when we use last we cant use first


so you can imagine the problem as 2 subproblems of the max sum of non adjacent elements

here we will divide the original array in 2 arrays
first will be from 0 to lastIndex-1 (which means we include the first element and exclude the last element)

last vector will be from index=1 to lastIndex (which means we will exclude the first element and go till the last element)

now the final answer will be the max of the answers of these 2 sub problems


____________________________________________



NOW:
 you may think of a solution where you will not divide the array in 2 parts
 so you will use the og same array only, but on iterating you will check that
 if you had previously chosen the first element, then when you reach the last element
 you will not choose the last element because you had earlier chosen the first element

 and when you dont choose the first element and when iterating, then you can choose
 the last element because you had not chosen the first element

 but this solution will not work
 WHY?

 because dp vector is the same and the dp is populated in the wrong way
 so wheen you first choose the first element then you iterate through the array...
 you also keep populating the dp vector
 but here you populate sub problems of the solution considering that you are not choosing
 the last element

 and when you do your another iteration of the array when you decide not to choose the
 first element and choose the last element
 then you dp vector is already populated with values from the previous iteration where
 last element is not considered
 so the dp is populated with wrong data for this iteration

 so this solution leads to wrong answers


 SO the correct solution is to have 2 vectors
 one from 0 to lastIndex-1
 and another from 1 to lastIndex


*/

long long solveRec(vector<int> &nums, vector<long long> &dp, int index)
{

    // base cases
    if (index >= nums.size())
    {
        return 0;
    }

    // check dp
    if (dp[index] != -1)
    {
        return dp[index];
    }

    // include or exclude
    long long include = nums[index] + solveRec(nums, dp, index + 2);

    long long exclude = 0 + solveRec(nums, dp, index + 1);

    // store in dp and return
    return dp[index] = max(include, exclude);
}

long long int houseRobber(vector<int> &nums)
{
    // Write your code here.

    int n = nums.size();

    if (n == 1)
    {
        return nums[0];
    }

    // now we will solve for 2 vectors
    // first will be where first index is considered in the array but the last element is not
    // second will be where last index is considere in the array but the first element is not

    vector<int> first, last;

    for (int i = 0; i < n; i++)
    {

        // populate first vector
        if (i != n - 1)
        {
            first.push_back(nums[i]);
        }

        // populate last vector
        if (i != 0)
        {
            last.push_back(nums[i]);
        }
    }

    vector<long long> dp1(nums.size() + 1, -1);
    vector<long long> dp2(nums.size() + 1, -1);

    return max(solveRec(first, dp1, 0), solveRec(last, dp2, 0));
}

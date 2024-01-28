#include <bits/stdc++.h>
using namespace std;

// NOTE: you can also declare dp size based on the N and target given in the question
int dp[16][10001];

int solve(int ind, int x, vector<int> &num)
{
    // base cases
    if (x == 0)
        return 0;

    if (ind == num.size())
        return 1e9;

    if (x < 0)
        return 1e9;

    // check in dp
    if (dp[ind][x] != -1)
        return dp[ind][x];

    // There are 2 possibilities: whether to take the current element or not to take

    // When you take, dont increment the index, because as per question we can take the element unlimited number of times... so we will stop when the target becomes less than 0
    int take = 1 + solve(ind, x - num[ind], num);

    // We will increase the index here because we are not considering this element here. So we will end up when the index is out of defined range in base case (if we keep ignoring all elements)
    int nottake = solve(ind + 1, x, num);

    // store the answer (minimum number of coins required to make this sum)
    return dp[ind][x] = min(take, nottake);
}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.

    for (int i = 0; i <= num.size(); i++)
    {
        for (int j = 0; j <= x; j++)
        {
            dp[i][j] = -1;
        }
    }

    int ans = solve(0, x, num);
    if (ans == 1e9)
        ans = -1;
    return ans;
}

int main()
{

    return 0;
}
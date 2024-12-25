#include <bits/stdc++.h>
using namespace std;

/*
RECURSION PROBLEM
https://www.codingninjas.com/codestudio/problems/easy_7544624?topList=21-days-beginner-coding-challenge
*/

#include <bits/stdc++.h>

void solve(long long target, string curr, long long currDigs, long long targetDigs, vector<long long> &ans)
{

    // base case
    if (currDigs > targetDigs)
    {
        return;
    }

    long long temp;

    // append 2
    curr = curr + "2";
    temp = stoll(curr);
    if (temp <= target)
    {
        ans.push_back(temp);
        solve(target, curr, currDigs + 1, targetDigs, ans);
    }

    // append 5
    curr = curr.substr(0, curr.length() - 1);
    curr = curr + "5";
    temp = stoll(curr);
    if (temp <= target)
    {
        ans.push_back(temp);
        solve(target, curr, currDigs + 1, targetDigs, ans);
    }
}

vector<long long> createSequence(long long n)
{
    // Write your code here.

    string curr = "";
    vector<long long> ans;
    long long targetDigs = to_string(n).length();

    solve(n, curr, 0, targetDigs, ans);

    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{

    return 0;
}
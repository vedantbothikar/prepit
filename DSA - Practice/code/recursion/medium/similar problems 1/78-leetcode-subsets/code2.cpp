#include <bits/stdc++.h>
using namespace std;

/*

This code studio problem is same as 78-leetcode

Just the difference is that we are using strings here



https://www.codingninjas.com/codestudio/problems/subsequences-of-string_985087?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_16

*/

void solve(string str, string output, int index, vector<string> &ans)
{

    if (index >= str.length())
    {
        if (output != "")
        {
            ans.push_back(output);
        }
        return;
    }

    // exclude the character
    solve(str, output, index + 1, ans);

    // include
    output = output + str[index];
    solve(str, output, index + 1, ans);
}

vector<string> subsequences(string str)
{

    // Write your code here

    vector<string> ans;
    string output;
    int index = 0;

    solve(str, output, index, ans);

    return ans;
}

int main()
{

    return 0;
}
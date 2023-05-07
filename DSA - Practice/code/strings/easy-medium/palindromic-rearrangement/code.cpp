#include <bits/stdc++.h>
using namespace std;

/*
https://www.codingninjas.com/codestudio/problems/palindromic-rearrangement_2825052?topList=jp-morgan-interview-questions

STRING
Problem Statement: Palindromic Rearrangement


*/

#include <bits/stdc++.h>

bool solve(int n, string &str, unordered_map<char, int> &m)
{

    // traverse string
    // store the number of occurrences of each character

    for (int i = 0; i < str.length(); i++)
    {
        char temp = str[i];
        m[temp]++;
    }

    // traverse the map
    // if the characters having odd number of occurrences are more than 1, then return false

    int oddOcc = 0;
    for (auto temp : m)
    {
        if (temp.second % 2 != 0)
        {
            oddOcc++;
        }
    }

    if (oddOcc > 1)
    {
        return false;
    }

    return true;
}

bool palidromicRearrangement(int n, string &str)
{
    // Write your code here.

    unordered_map<char, int> m;

    return solve(n, str, m);
}

int main()
{

    return 0;
}
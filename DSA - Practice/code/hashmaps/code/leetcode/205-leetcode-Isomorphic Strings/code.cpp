#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{

    // we need to check if
    // s & t are isomorphic
    // which means we need to compare it both ways
    // for example: bar and foo are isomorphic
    // BUT foo and bar are not isomorphic
    // so the final answer will be false

    unordered_map<char, char> m1;
    unordered_map<char, char> m2;

    for (int i = 0; i < s.length(); i++)
    {

        if (!m1[s[i]])
        {
            if (!m2[t[i]])
            {
                m1[s[i]] = t[i];
                m2[t[i]] = s[i];
            }
        }

        if (m1[s[i]] != t[i] || m2[t[i]] != s[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// NOT EFFICIENT SOLUTION
// IT WILL GIVE TLE ERROR

// sliding window type
string removeDuplicates(string s)
{

    // take a window length of 2
    // if elements match - erase

    int i = 0;

    while (i + 1 < s.length())
    {

        if (s[i] == s[i + 1])
        {
            s.erase(i, 2);
            i = 0;
        }
        else
        {
            i++;
        }
    }

    return s;
}

int main()
{

    return 0;
}
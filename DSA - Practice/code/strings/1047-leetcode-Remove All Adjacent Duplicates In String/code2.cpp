#include <bits/stdc++.h>
using namespace std;

// HERE I have used vector as a stack
// This is essentially a stack question

string removeDuplicates(string s)
{

    // originally this should be solved using stack
    // here we are using the vector as a stack

    vector<char> v;

    for (int i = 0; i < s.length(); i++)
    {

        // we are checking the size of the vector as well
        // because if size is 0
        // then v.back() will give an error
        //Calling this back function on an empty container
        // causesundefined behavior.
        if (v.size() && v.back() == s[i])
        {
            v.pop_back();
        }
        else
        {
            v.push_back(s[i]);
        }
    }

    // now the vector has our solution

    string ans = "";

    for (auto j : v)
    {
        ans += j;
    }

    return ans;
}

int main()
{

    return 0;
}
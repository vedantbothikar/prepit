#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{

    int start = 0;
    int end = s.length() - 1;
    bool ans = true;

    while (start <= end)
    {

        // check if the letters are alphanum
        if (!isalnum(s[start]))
        {
            start++;
        }
        else if (!isalnum(s[end]))
        {
            end--;
        }
        else
        {

            if (tolower(s[start]) != tolower(s[end]))
            {
                return false;
            }
            else
            {
                start++;
                end--;
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}
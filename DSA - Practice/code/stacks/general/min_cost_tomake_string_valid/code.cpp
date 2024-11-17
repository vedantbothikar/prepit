#include <bits/stdc++.h>
using namespace std;

bool isValid(string str)
{

    //push open brackets in stack
    // if closed bracket is encountered, check if top is corresponding open bracket
    // if not, return false
    // if yes, pop top and go to next iteration

    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] == '[' or str[i] == '(' or str[i] == '{')
        {
            s.push(str[i]);
        }
        else
        {

            // corner case "]" or "]]" etc
            if (s.empty())
            {
                return false;
            }

            if (s.top() == '[' and str[i] == ']')
            {
                s.pop();
            }
            else if (s.top() == '(' and str[i] == ')')
            {
                s.pop();
            }
            else if (s.top() == '{' and str[i] == '}')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }

    // case: "(" or "((" etc
    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int countOpening(string str)
{
    int opening = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{')
        {
            opening++;
        }
    }
    return opening;
}

void removeValid(string &str)
{

    stack<char> s;
    int len = str.length();

    for (int i = 0; i < len; i++)
    {
        if (str[i] == '{')
        {
            s.push(str[i]);
        }
        else
        {
            // str[i] is closing bracket

            if (!s.empty() and s.top() == '{')
            {
                s.pop();
            }
            else
            {
                s.push(str[i]);
            }
        }
    }

    // now stack has all the characters that are making the string         invalid

    int stackLen = s.size();
    str = "";
    for (int i = 0; i < stackLen; i++)
    {
        str = s.top() + str;
        s.pop();
    }
}

int findMinimumCost(string str)
{

    // odd length
    int strLen = str.length();
    if (strLen & 1)
    {
        return -1;
    }

    // check if valid
    bool validity = isValid(str);
    if (validity)
    {
        return 0;
    }

    // even length and invalid

    // remove the part that is valid

    removeValid(str);

    int opening = countOpening(str);
    int closing = str.length() - opening;

    int ans = ((opening + 1) / 2) + ((closing + 1) / 2);

    return ans;
}
int main()
{

    cout << findMinimumCost("{{{}");

    return 0;
}
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

int main()
{

    return 0;
}
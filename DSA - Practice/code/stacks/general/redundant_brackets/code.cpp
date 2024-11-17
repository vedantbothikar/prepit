#include <bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &s)
{
    // Write your code here.
    // loop on string
    // if opening bracket or operator- push in stack
    // if closing bracket- check if stack top is operator
    // if not return false
    // if true pop operator until opening bracket

    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {

        char ch = s[i];

        // if character is an opening bracket or an operator
        if (ch == '(' or ch == '+' or ch == '-' or ch == '*' or ch == '/')
        {
            st.push(ch);
        }

        else
        {
            // means ch is either alphabet or closing bracket

            // if closing bracket
            if (ch == ')')
            {

                // if stack top is opening bracket return true                         (redundant)
                if (st.top() == '(')
                {
                    return true;
                }

                // pop operators until you get opening bracket
                while (st.top() != '(')
                {
                    st.pop();
                }

                // popping the opening bracket now
                st.pop();
            }
        }
    }

    return false;
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

string replaceSpaces(string &str)
{
    // Write your code here.
    string str2 = "@40";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {

            str.replace(i, 1, str2);
        }
    }

    return str;
}

int main()
{

    return 0;
}
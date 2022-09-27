#include <bits/stdc++.h>
using namespace std;

void reverserString(string &str)
{

    stack<int> s;
    int len = str.length();

    // push every letter in stack
    for (int i = 0; i < len; i++)
    {
        s.push(str[i]);
    }

    str = "";

    // pop and append every element in str
    for (int i = 0; i < len; i++)
    {
        str += s.top();
        s.pop();
    }
}

int main()
{

    string str = "vedant";
    reverserString(str);

    cout << endl;
    cout << "After reversing: " << str << endl;
    cout << endl;

    return 0;
}
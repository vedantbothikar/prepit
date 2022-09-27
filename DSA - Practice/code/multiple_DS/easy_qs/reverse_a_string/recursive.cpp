#include <bits/stdc++.h>
using namespace std;

void myfunc(vector<char> &s, int start)
{

    int len = s.size();

    if (start > len - 1 - start)
    {
        return;
    }

    swap(s[start], s[len - 1 - start]);
    myfunc(s, ++start);
}

void reverseString(vector<char> &s)
{

    myfunc(s, 0);
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
/*
 in while condition, we are checking 2 things:
 1. if the string's length has now become 0, then 
 don't check further
 2. if the substring is not present, then don't 
 check further

(Note: 

Read:
https://cplusplus.com/reference/string/string/find/

If substring is found: `find` returns
The **position** of the **first character** of the 
first match.


if the substring is NOT present, `find` returns 
 `string::npos`

 `npos` is a static member constant value with the 
 greatest possible value for an element of type size_t.

`size_t` is an unsigned integral type

)

*/

string removeOccurrences(string s, string part)
{

    while (s.length() != 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part), part.length());
    }

    return s;
}

int main()
{

    return 0;
}
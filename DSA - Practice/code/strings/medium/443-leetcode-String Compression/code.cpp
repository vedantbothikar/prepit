#include <bits/stdc++.h>
using namespace std;

/*

- https://leetcode.com/problems/string-compression/description/

We are just modifying a part of the given vector and 
then we are returning the length of vector that is
useful

thus we are not modifying the `entire` vector
we are just modifying some starting part of it
and then returning length of that part

*/

/*

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1)

*/

int compress(vector<char> &chars)
{

    int i = 0;
    int j = 0;
    int ansIndex = 0;
    int n = chars.size();

    while (i < n)
    {

        j = i + 1;

        // go ahead till same characters
        while (j < n && chars[i] == chars[j])
        {
            j++;
        }

        // you will reach here when
        // new character or end of vector

        // store the character the location
        chars[ansIndex] = chars[i];
        ansIndex++;

        // store the count
        int count = j - i;

        if (count > 1)
        {
            // store count digit wise
            string s = to_string(count);
            for (char ch : s)
            {
                chars[ansIndex] = ch;
                ansIndex++;
            }
        }

        i = j;
    }

    return ansIndex;
}

int main()
{

    return 0;
}
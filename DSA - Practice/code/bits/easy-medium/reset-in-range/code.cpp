#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
#include <string>

/*


BIT MANIPULATION

https://www.codingninjas.com/codestudio/problems/reset-in-range_972998?topList=jp-morgan-interview-questions

- we know how to convert decimal to binary
- during that process, when we reach to the rth digit start resetting process
- when we reach to lth digit, stop the resetting process

PROCESS to convert decimal to binary:
- loop
- divide by 2 every time
- the remainder is the binary value
- append remainder to the string
- but the issue is that the output is the reverse of this string


- so we need to first convert decimal to binary completely
- then reverse
- then reset the bits


*/

int solve(int n, int l, int r)
{

    string s = "";
    int count = 0;

    // decimal to binary
    while (n != 0)
    {

        int rem = n % 2;
        n = n / 2;

        count++;

        if (count >= r and count <= l)
        {
            rem = 0;
        }

        s = to_string(rem) + s;
    }

    int value = 0;

    // binary to decimal
    for (int i = s.length() - 1; i >= 0; i--)
    {

        string sub = s.substr(i, 1);
        int dig = stoi(sub);
        value += dig * pow(2, s.length() - 1 - i);
    }

    return value;
}

int resetAllBitsInRange(int n, int l, int r)
{
    // Write your code here.

    return solve(n, l, r);
}

int main()
{

    return 0;
}
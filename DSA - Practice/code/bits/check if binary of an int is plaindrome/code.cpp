#include <bits/stdc++.h>
using namespace std;

/*

Check If Binary Representation of a Number is Palindrome

https://www.codingninjas.com/codestudio/problems/check-palindrome_920555?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_13


*/

bool checkPalindrome(long long N)
{
    // convert integer to binary string
    // use two pointer approach in binary string

    // convert to binary
    string ans = "";
    while (N != 0)
    {
        int rem = N % 2;
        ans += rem;

        N = N / 2;
    }

    // check if palindrome

    // APPROACH 1

    //     string rev = ans;
    //     reverse(rev.begin(), rev.end());

    //     if(ans == rev){
    //         return true;
    //     }
    //     else {
    //         return false;
    //     }

    // APPROACH 2
    // 2 pointer approach

    int start = 0, end = ans.length() - 1;
    while (start <= end)
    {
        if (ans[start] != ans[end])
        {
            return false;
        }

        start++;
        end--;
    }

    return true;
}

int main()
{

    return 0;
}
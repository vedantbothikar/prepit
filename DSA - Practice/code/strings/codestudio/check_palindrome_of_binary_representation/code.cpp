#include <bits/stdc++.h>
using namespace std;

/*


https://gist.github.com/vedantbothikar/03ac6a8557e9ddcd14e05c7c40e6e0fd

READ THIS


 VERY VERY IMPORTANT POINT MENTIONED

*/

/*

Question

- https://www.codingninjas.com/codestudio/problems/check-palindrome_920555?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_13
- https://practice.geeksforgeeks.org/problems/palindrome-numbers0942/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


*/

int checkPalindrome2(string str, int start)
{

    int end = str.length() - 1 - start;

    // base case
    if (start >= end)
    {
        return 1;
    }

    if (str[start] != str[end])
    {
        return 0;
    }
    else
    {
        checkPalindrome2(str, start++);
    }
}

identify segmentation fault

    int
    main()
{

    return 0;
}
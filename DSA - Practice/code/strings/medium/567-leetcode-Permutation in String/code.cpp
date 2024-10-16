#include <bits/stdc++.h>
using namespace std;

/*
- https://leetcode.com/problems/permutation-in-string/description/
*/

bool checkEqual(int count1[26], int count2[26])
{

    for (int i = 0; i < 26; i++)
    {
        if (count1[i] != count2[i])
        {
            return false;
        }
    }

    return true;
}

bool checkInclusion(string s1, string s2)
{

    if (s1.length() > s2.length())
    {
        return false;
    }

    // store count of each character of s1
    int count1[26] = {0};

    for (int i = 0; i < s1.length(); i++)
    {
        int index = s1[i] - 'a';
        count1[index]++;
    }

    // count of s2 => take count of substring of window size only
    // window size is the size of s1

    int windowsize = s1.length();
    int i = 0;
    int count2[26] = {0};

    // STORING COUNT OF s2 of window size for FIRST WINDOW
    // i should be less than windowsize as we want to store count of
    // characters only in that window
    // i should also be less than s2's length because if could be
    // possible that s1's length is greater than s2's length
    while (i < windowsize)
    {
        int index = s2[i] - 'a';
        count2[index]++;

        i++;
    }

    // once both counts are stored, compare if they are equal
    bool equal = checkEqual(count1, count2);
    if (equal)
    {
        return true;
    }

    // if they are not equal
    // keep checking for the next windows

    // i will initially be at the index of 1 greater than the window size
    while (i < s2.length())
    {

        // two tasks to be done here
        // 1. increment count of new character in new window
        // 2. decrement count of old character of the old window

        // task 1
        int index = s2[i] - 'a';
        count2[index]++;

        // task 2
        index = s2[i - windowsize] - 'a';
        count2[index]--;

        if (checkEqual(count1, count2))
        {
            return true;
        }

        i++;
    }

    return false;
}

int main()
{

    return 0;
}
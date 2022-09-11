#include <bits/stdc++.h>
using namespace std;

/*

This is same logic as code.cpp

just that we are here using vectors and then comparing


*/

bool checkEqual(vector<char> v1, vector<char> v2)
{

    // we are checking if the two vectors have the same characers
    // NOTE: we can't simple check if v1 == v2
    // this is because they both might have the same characters
    // but in different order
    // v1== v2 will also check for order of the elements
    // in our case, order of elements doesn't matter

    // storing count of characters of both the vectors
    int count1[26] = {0};
    int count2[26] = {0};

    for (int i = 0; i < v1.size(); i++)
    {

        int index1 = v1[i] - 'a';
        int index2 = v2[i] - 'a';

        count1[index1]++;
        count2[index2]++;
    }

    // compare the count of both the characters

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

    // convert s1 to vector of chars
    vector<char> v1(s1.begin(), s1.end());

    // sliding window
    // i is the index of first character of window

    int i = 0;
    int windowsize = s1.length();

    while (i + windowsize <= s2.length())
    {

        vector<char> v2(s2.begin() + i, s2.begin() + i + windowsize);

        if (checkEqual(v1, v2))
        {
            return true;
        }

        i++;
    }

    return false;
}
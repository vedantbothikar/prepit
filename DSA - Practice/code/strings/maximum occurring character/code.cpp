#include <bits/stdc++.h>
using namespace std;

// THIS SOLUTION WILL WORK ONLY FOR LOWERCASE CHARACTERS

char getMaxOccuringChar(string str)
{
    // Your code here

    int arr[26] = {0};

    // update counts
    for (int i = 0; i < str.length(); i++)
    {
        int num = str[i] - 'a';
        arr[num]++;
    }

    // find the greatest count
    int maxnum = 0;
    char maxchar = 'a';

    for (int i = 0; i < 26; i++)
    {
        if (arr[i] > maxnum)
        {
            maxnum = arr[i];
            maxchar = 'a' + i;
        }
    }

    return maxchar;
}

int main()
{

    return 0;
}
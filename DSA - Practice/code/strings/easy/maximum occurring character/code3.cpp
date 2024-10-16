#include <bits/stdc++.h>
using namespace std;

// This code will work for upper & lower case

// it will consider 'A' and 'a' as the same

char getMaxOccCharacter(string s)
{

    int arr[26] = {0};

    //create an array of count of characters
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        int number = 0;

        if (ch >= 'a' && ch <= 'z')
        {
            //lowercase
            number = ch - 'a';
        }
        else
        {
            // upper case
            number = ch - 'A';
        }

        arr[number]++;
    }

    //find maximum occ character
    int maxi = -1, ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (maxi < arr[i])
        {
            ans = i;
            maxi = arr[i];
        }
    }

    return 'a' + ans;
}

int main()
{

    cout << endl;
    cout << getMaxOccCharacter("AAAaagggg") << endl;

    char arr[] = {'a', 'b', 'c', 'd'};
    cout << "LENGTH OF CHAR ARR: " << strlen(arr) << endl;

    return 0;
}
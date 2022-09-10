#include <bits/stdc++.h>
using namespace std;

// THIS CAN WE BE USED FOR UPPERCASE CHARACTERS AS WELL

// BUT IF  TWO CHARACTERS HAVE THE SAME COUNT
// THEN IT WILL RETURN THE CHARACTER THAT WE
// CHECKED LATER IN THE STRING

// TO RETURN THE LEXICOGRAPHICALLY SMALLER CHARACTER,
// YOU NEED A SEPARATE LOOP FOR CHECKING
//THE MAX COUNT (HERE EVERYTHING IS IN THE SAME LOOP)

char getMaxOccuringChar(string str)
{
    // Create array to keep the count of individual
    // characters and initialize the array as 0
    int count[256] = {0};

    // Construct character count array from the input
    // string.
    int len = str.length();
    int max = 0; // Initialize max count
    char result; // Initialize result

    // Traversing through the string and maintaining
    // the count of each character
    for (int i = 0; i < len; i++)
    {
        count[str[i]]++;
        if (max < count[str[i]])
        {
            max = count[str[i]];
            result = str[i];
        }
    }

    return result;
}

int main()
{

    return 0;
}
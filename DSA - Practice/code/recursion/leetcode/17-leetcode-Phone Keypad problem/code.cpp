#include <bits/stdc++.h>
using namespace std;

void solve(string digits, string output, int index, vector<string> &ans, vector<char> alphabet)
{
    // base case
    if (index >= digits.length())
    {
        return;
    }

    string output1 = output, output2 = output, output3 = output, output4 = output;

    char charnum = digits[index];
    string strnum;
    strnum = charnum;
    int intnum = stoi(strnum);

    char firstcharacter = alphabet[intnum];
    char secondcharacter = firstcharacter + 1;
    char thirdcharacter = firstcharacter + 2;
    char fourthcharacter = firstcharacter + 3;

    bool fourth = false;
    if (intnum == 7 || intnum == 9)
    {
        fourth = true;
    }

    cout << "firstcharacter " << firstcharacter << " value: " << intnum + 95 << endl;

    output1 = output1 + firstcharacter;
    output2 = output2 + secondcharacter;
    output3 = output3 + thirdcharacter;
    output4 = output4 + fourthcharacter;

    solve(digits, output1, index + 1, ans, alphabet);
    if (output1.length() == digits.length())
    {
        ans.push_back(output1);
    }

    solve(digits, output2, index + 1, ans, alphabet);
    if (output2.length() == digits.length())
    {
        ans.push_back(output2);
    }

    solve(digits, output3, index + 1, ans, alphabet);
    if (output3.length() == digits.length())
    {
        ans.push_back(output3);
    }

    if (fourth)
    {
        solve(digits, output4, index + 1, ans, alphabet);
        if (output4.length() == digits.length())
        {
            ans.push_back(output4);
        }
    }
}

vector<string> letterCombinations(string digits)
{

    vector<string> ans;
    int index = 0;
    string output = "";
    vector<char> alphabet = {'a', 'a', 'a', 'd', 'g', 'j', 'm', 'p', 't', 'w'};

    solve(digits, output, index, ans, alphabet);

    return ans;
}

int main()
{

    return 0;
}
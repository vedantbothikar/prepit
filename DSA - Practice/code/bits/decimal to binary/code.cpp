#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    // A
    // int ans = 0;
    int i = 0;
    string ans = "";

    while (n != 0)
    {

        int bit = n & 1;

        // append the bits
        ans = ans + to_string(bit);

        // A
        // ans = ans + pow(10,i)*bit;

        n = n >> 1;
        i++;
    }

    // reverse the string
    for (int j = ans.length(); j >= 0; j--)
    {
        cout << ans[j];
    }

    return 0;
}
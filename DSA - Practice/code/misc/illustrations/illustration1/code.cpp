#include <bits/stdc++.h>
using namespace std;

/*

check if count is single digit
then it is considered as single character

if count is multi digit
it is considered as multi character

*/

int main()
{

    int count = 12;
    string str = to_string(count);

    for (int i = 0; i < str.length(); i++)
    {
        cout << str[i] << " - ";
    }
    cout << endl;

    return 0;
}

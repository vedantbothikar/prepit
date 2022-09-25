#include <bits/stdc++.h>
using namespace std;

/*

- Here we are traversing the binary form 
of given integer, and while traversing
if we get `1`
then append 0 to str
if we get `0`
then append 1 to str
(keep repeating this only until n==0)



in this way we get the complement of the number
but this is currently in reverse form

- reverse the string

- now this string is like eg: "010"
- we need to convert this to decimal form

- use bin to dec logic 



*/

int bintodec(string str)
{
    //for every bit
    // sum += pow(2,i)

    int i = 0;
    int sum = 0;

    while (str.size())
    {

        // getting the last bit in integer form
        char last = str.back();
        string s(1, last);
        int bit = stoi(s);

        sum += pow(2, i) * bit;

        i++;
        str.resize(str.size() - 1);
    }

    return sum;
}

int bitwiseComplement(int n)
{

    if (n == 0)
    {
        return 1;
    }

    string str = "";
    while (n != 0)
    {

        //check if the last bit is 1
        // if 1
        // then append 0 to str
        // else append 1 to str
        // reverse str

        if (n & 1)
        {
            str += "0";
        }
        else
        {
            str += "1";
        }

        n = n >> 1;
    }

    reverse(str.begin(), str.end());

    int result = bintodec(str);

    return result;
}

int main()
{

    int n;
    cin >> n;

    cout << bitwiseComplement(n);

    return 0;
}
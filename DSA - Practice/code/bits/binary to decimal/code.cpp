#include <bits/stdc++.h>
using namespace std;

/*

0010100010...101

whenever I get 1
then I will do

sum = sum + pow(2,i)

*/

int bintodec(int n)
{

    int sum = 0;
    int i = 0;

    while (n != 0)
    {

        int bit = n & 1;

        // why not int digit = n%10

        // cout<<bit<<endl;

        if (bit)
        {
            sum += pow(2, i);
        }

        i++;
        n = n / 10;
    }

    return sum;
}

int main()
{

    int n;
    cin >> n;
    cout << bintodec(n);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

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

    cout << sum;

    return 0;
}
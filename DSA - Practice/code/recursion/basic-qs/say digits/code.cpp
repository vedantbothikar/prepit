#include <bits/stdc++.h>
using namespace std;

// input: 412
// output: four one two

// print the remainder

void sayDigits(int n, vector<string> v)
{

    if (n == 0)
    {
        return;
    }

    sayDigits(n / 10, v);

    cout << v[n % 10] << " ";
}

int main()
{
    int n;
    cin >> n;

    vector<string> v = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    sayDigits(n, v);

    return 0;
}
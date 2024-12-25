#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{

    if (n == 0)
    {
        return 1;
    }

    int small = factorial(n - 1);
    int big = n * small;

    return big;
}

int main()
{

    cout << "input: " << endl;
    int n;
    cin >> n;

    cout << "Factorial: " << factorial(n) << endl;

    return 0;
}
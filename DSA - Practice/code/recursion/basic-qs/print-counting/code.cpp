#include <bits/stdc++.h>
using namespace std;

void printCounting(int n)
{

    if (n == -1)
    {
        return;
    }

    cout << n
         << " ";
    return printCounting(n - 1);
}

int main()
{

    cout << "input: " << endl;
    int n;
    cin >> n;

    cout << "Counting: " << endl;

    printCounting(n);

    return 0;
}
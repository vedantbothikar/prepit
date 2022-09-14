#include <bits/stdc++.h>
using namespace std;

// head recursion
// prints 0 1 2 3 4 5
void printCountingHead(int n)
{

    if (n == -1)
    {
        return;
    }

    printCountingHead(n - 1);

    cout << n << " ";
}

// tail recursion
// prints 5 4 3 2 1 0
void printCountingTail(int n)
{

    if (n == -1)
    {
        return;
    }

    cout << n
         << " ";
    return printCountingTail(n - 1);
}

int main()
{

    cout << "input: " << endl;
    int n;
    cin >> n;

    cout << "Counting: Tail recursion -> " << endl;

    printCountingTail(n);

    cout << endl;

    cout << "Counting: Head recursion -> " << endl;

    printCountingHead(n);

    cout << endl;

    return 0;
}
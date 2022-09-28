#include <bits/stdc++.h>
using namespace std;

// RECURSIVE APPROACH

// NO EXTRA SPACE

void solve(stack<int> &inputStack, int count, int N)
{

    // base case
    if (count == N / 2)
    {
        // we reached middle element
        inputStack.pop();
        return;
    }

    int element = inputStack.top();
    inputStack.pop();

    solve(inputStack, ++count, N);

    inputStack.push(element);
}

void deleteMiddle(stack<int> &inputStack, int N)
{

    // recursive approach

    int len = N + 1;
    int count = 0;

    solve(inputStack, count, N);
}
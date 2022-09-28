#include <bits/stdc++.h>
using namespace std;

void insertSorted(stack<int> &s, int x)
{
    if (s.empty() or s.top() <= x)
    {
        s.push(x);
        return;
    }

    int element = s.top();
    s.pop();

    insertSorted(s, x);

    s.push(element);
}

void sortStack(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }

    int element = stack.top();
    stack.pop();

    sortStack(stack);

    insertSorted(stack, element);
}

int main()
{

    return 0;
}
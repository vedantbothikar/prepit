#include <bits/stdc++.h>
using namespace std;

/*

Approach:

We take the top element of the stack (pop)

// recursion will handle the process of 
reversing other elements of the stack

insert the popped element at the bottom of the stack

Example: 

Check notes


*/

void insertAtBottom(stack<int> &s, int x)
{

    // base case
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int element = s.top();
    s.pop();

    insertAtBottom(s, x);

    s.push(element);
}

void solve(stack<int> &s, int count)
{

    // base case
    if (count == 0)
    {
        return;
    }

    int element = s.top();
    s.pop();

    solve(s, count - 1);

    insertAtBottom(s, element);
}

void reverseStack(stack<int> &s)
{
    // Write your code here

    solve(s, s.size());
}

int main()
{

    return 0;
}
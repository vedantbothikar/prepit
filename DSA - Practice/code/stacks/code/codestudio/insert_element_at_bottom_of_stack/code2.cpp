#include <bits/stdc++.h>
using namespace std;

// USING EXTRA SPACE

// method 2:
// we need to reduce space used
// so let's try recursion
// base case when stack is empty
// base case hit: insert the new element
// basic step is to pop the element
// then recursive call
// then push the element

void solve(stack<int> &myStack, int x)
{

    // base case
    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }

    int element = myStack.top();
    myStack.pop();

    solve(myStack, x);

    myStack.push(element);
}

stack<int> pushAtBottom(stack<int> &myStack, int x)
{

    solve(myStack, x);

    return myStack;
}

int main()
{

    return 0;
}
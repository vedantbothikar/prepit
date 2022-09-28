#include <bits/stdc++.h>
using namespace std;

// USING EXTRA SPACE

// method 1:
// use extra stack
// pop elements from stack1 and put in stack2 until empty
// insert the new element
// push all elements from stack2 to stack1
// Space complexity: O(N)
// Time complexity: O(N)

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    stack<int> s;
    int len = myStack.size();

    for (int i = 0; i < len; i++)
    {
        s.push(myStack.top());
        myStack.pop();
    }

    myStack.push(x);

    for (int i = 0; i < len; i++)
    {
        myStack.push(s.top());
        s.pop();
    }

    return myStack;
}

int main()
{

    return 0;
}
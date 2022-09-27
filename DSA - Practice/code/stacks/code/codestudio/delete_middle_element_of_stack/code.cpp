#include <bits/stdc++.h>
using namespace std;

void printStack(stack<int> s)
{
    cout << "Printing Stack: " << endl;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;
}

void deleteMiddle(stack<int> &inputStack, int N)
{

    int len1 = N + 1;
    int mid;

    /*
Note according to problem the stack is reverse so need to
do these things

But leave this focus on logic
*/

    if (len1 & 1)
    {
        mid = len1 / 2;
    }
    else
    {
        mid = (len1 / 2) - 1;
    }

    // pop elements from inputStack for mid times
    // store elements in a new stack

    // here we pop only elements before mid
    stack<int> s;
    for (int i = 0; i < mid; i++)
    {
        s.push(inputStack.top());
        inputStack.pop();
    }

    // here we pop mid
    inputStack.pop();

    // push elements other elements back in orginal stack
    int len2 = s.size();
    for (int i = 0; i < len2; i++)
    {
        inputStack.push(s.top());
        s.pop();
    }
}

int main()
{

    stack<int> s;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        s.push(element);
    }

    deleteMiddle(s, n - 1);

    for (int i = 0; i < n - 1; i++)
    {
        cout << s.top();
        s.pop();
    }

    return 0;
}
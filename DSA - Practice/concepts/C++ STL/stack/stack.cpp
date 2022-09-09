#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "----------STACK----------" << endl;

    cout << "----------INITIALIZATION----------" << endl;

    stack<string> s;

    cout << "----------PUSH----------" << endl;

    s.push("vedant");
    s.push("bothikar");
    s.push("pict");

    cout << "----------TOP----------" << endl;

    cout << "top element " << s.top() << endl;

    cout << "----------POP----------" << endl;
    s.pop();
    cout << "top element " << s.top() << endl;

    cout << "---------SIZE, EMPTY-----------" << endl;
    cout << "size: " << s.size() << endl;
    cout << "empty or not: " << s.empty() << endl;

    return 0;
}
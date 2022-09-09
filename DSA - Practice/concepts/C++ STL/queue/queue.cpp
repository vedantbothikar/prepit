#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "----------QUEUE----------" << endl;

    cout << endl;

    cout << "----------INITIALIZATION----------" << endl;

    queue<string> q;

    cout << endl;

    cout << "----------PUSH----------" << endl;

    q.push("vedant");
    q.push("bothikar");
    q.push("pict");

    cout << endl;
    cout << "----------FIRST----------" << endl;

    cout << "front element " << q.front() << endl;

    cout << endl;

    cout << "----------POP----------" << endl;
    q.pop();
    cout << "front element " << q.front() << endl;

    cout << endl;

    cout << "---------SIZE, EMPTY-----------" << endl;

    cout << "size: " << q.size() << endl;
    cout << "empty or not: " << q.empty() << endl;

    return 0;
}
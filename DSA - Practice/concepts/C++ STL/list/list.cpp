#include <bits/stdc++.h>
using namespace std;

/*

This list is a doubly linked list

- direct access not possible (at operation etc)

*/

void printList(list<int> &l)
{
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    cout << "----------LIST----------" << endl;

    cout << "----------INITIALIZATION----------" << endl;

    list<int> l;

    // list `l` copied to mylist
    list<int> mylist(l);

    // size 5  all elements initialized with `7`
    list<int> mynewlist(5, 7);

    cout << "mylist" << endl;
    printList(mylist);

    cout << "mynewlist" << endl;
    printList(mynewlist);

    cout << "----------PUSH----------" << endl;

    // front and back, both push are available
    l.push_back(1);
    l.push_front(2);
    printList(l);

    cout << "----------ERASE----------" << endl;

    // erases the first element
    l.erase(l.begin());
    printList(l);

    cout << "--------------------" << endl;

    cout << "SIZE: " << l.size();

    return 0;
}
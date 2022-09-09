#include <bits/stdc++.h>
using namespace std;

/*

Map
stores in key value pairs

a particular key can store only a particular value


map prints in sorted order

MAP
insert, erase, find, count  => O(logn)
uses red black tree or balanced tree

UNORDERED MAP
here the complexity is O(1)
uses hashtable

*/

void printMap(map<int, string> m)
{

    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }

    cout << endl;
}

int main()
{
    cout << "----------MAP----------" << endl;

    cout << endl;

    cout << "----------INITIALIZATION----------" << endl;

    map<int, string> m;

    cout << endl;

    cout << "----------PUSH----------" << endl;

    m[1] = "vedant";
    m[5] = "karan";
    m[2] = "tanuj";

    // another method
    m.insert({6, "akshit"});

    printMap(m);

    cout << endl;

    cout << "----------COUNT----------" << endl;
    // this is usually used to check if the element is present or not
    // if present, it returns 1
    // else returns 0
    cout << " 6th element is present or not? : " << m.count(6) << endl;

    cout << endl;

    cout << "----------ERASE----------" << endl;
    m.insert({10, "random"});
    cout << "Before erase" << endl;
    printMap(m);

    // erases key 10
    m.erase(10);

    cout << "After erase" << endl;
    printMap(m);

    cout << endl;

    cout << "----------FIND----------" << endl;

    // find always returns an iterator

    auto it = m.find(5);
    for (auto i = it; i != m.end(); i++)
    {
        cout << (*i).first << " " << (*i).second << endl;
    }

    cout << endl;

    cout << "---------SIZE, EMPTY-----------" << endl;

    cout << "size: " << endl;
    cout << "empty or not: " << endl;

    return 0;
}
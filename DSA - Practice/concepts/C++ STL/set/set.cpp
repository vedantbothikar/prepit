#include <bits/stdc++.h>
using namespace std;

/*

- SET stores only UNIQUE elements
- Can't modify elements.. You can either 
store or delete elements.. You cannot modify them
- unordered set, stores in random order
- set is slower than unordered set


insert, find, erase, count  => O(logn)

*/

void printSet(set<int> s)
{

    for (auto i : s)
    {
        cout << i << " ";
    }

    cout << endl;
}

int main()
{
    cout << "----------PRIORITY QUEUE----------" << endl;

    cout << endl;

    cout << "----------INITIALIZATION----------" << endl;

    // this will act as max heap
    set<int> s;

    // this will act as min heap
    priority_queue<int, vector<int>, greater<int>> mini;

    cout << endl;

    cout << "----------INSERT----------" << endl;

    // takes O(logN)
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(9);
    s.insert(0);

    // prints in sorted manner
    printSet(s);

    cout << endl;

    cout << "---------COUNT-----------" << endl;
    cout << "Number 5 is present or not?: " << s.count(5) << endl;

    cout << endl;

    cout << "----------FIND----------" << endl;

    // find returns iterator of location of 5
    set<int>::iterator itr = s.find(5);
    cout << " value at itr: " << *itr << endl;

    for (auto i = itr; i != s.end(); i++)
    {
        cout << *i << " ";
    }

    cout << endl;

    cout << "----------ERASE----------" << endl;

    // delete first element
    s.erase(s.begin());

    // delete second element
    set<int>::iterator it = s.begin();
    it++;
    s.erase(it);

    printSet(s);

    cout << endl;

    cout << "---------SIZE, EMPTY-----------" << endl;

    cout << "size: " << s.size() << endl;
    cout << "empty or not: " << s.empty() << endl;

    return 0;
}
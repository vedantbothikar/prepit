#include <bits/stdc++.h>
using namespace std;

void printDeque(deque<int> &d)
{
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    /*

ALTERNATE printing method 

for(int i: d){
    cout<<i<<" ";
}

this will also work for vectors

    */
}

int main()
{
    cout << "--------------------" << endl;
    cout << "---------DEQUE---------" << endl;

    cout << "---------INITIALIZATION---------" << endl;

    deque<int> d;

    cout << "---------PUSH/POP BACK & FRONT---------" << endl;

    d.push_back(1);
    d.push_front(0);
    printDeque(d);

    d.pop_front();
    printDeque(d);

    d.push_back(2);
    d.push_back(3);

    cout << endl;

    cout << "---------FRONT BACK EMPTY-----------" << endl;

    cout << "FRONT: " << d.front() << endl;
    cout << "BACK: " << d.back() << endl;
    cout << "EMPTY: " << d.empty() << endl;

    cout << endl;

    cout << "----------AT Operation----------" << endl;

    cout << "AT operation: 2nd index: " << d.at(2) << endl;

    cout << endl;

    cout << "----------ERASE----------" << endl;

    cout << "Before erase, size: " << d.size() << endl;
    printDeque(d);

    // this will delete the first element
    d.erase(d.begin(), d.begin() + 1);
    cout << "After erase, size: " << d.size() << endl;
    printDeque(d);

    return 0;
}
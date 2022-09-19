#include <bits/stdc++.h>
using namespace std;

int main()
{

    // --------- creation
    unordered_map<string, int> m;

    // --------- insertion

    // method 1
    pair<string, int> p1 = make_pair("master", 300);
    m.insert(p1);

    // method 2
    pair<string, int> p2("vedant", 30);
    m.insert(p2);

    // method 3
    m["bothikar"] = 99;

    // --------- update
    m["bothikar"] = 100;

    // --------- search
    cout << "bothikar: " << m["bothikar"] << endl;
    cout << "master: " << m.at("master") << endl;

    // accessing unknown key
    // (key which has never been added)

    // error
    // ERROR:  terminate called after throwing an instance of 'std::out_of_range'
    // cout << "unknown: " << m.at("zwqqdvsd") << endl;

    // using square brackets
    cout << "unknown: " << m["zwqqdvsd"] << endl;

    // doing same thing but writing square brackets line first
    // now it won't give any error
    // WHY? read notes of hashmaps, *POINT 1*

    // using square brackets
    // key is initialized with value as zero
    cout << "unknown: " << m["absadadb"] << endl;

    // NO ERROR
    // cout << "unknown: " << m.at("absadadb") << endl;

    // --------- size
    cout << "size: " << m.size() << endl;

    // --------- count
    cout << "count: " << m.count("bafafasfro") << endl;
    cout << "count: " << m.count("vedant") << endl;

    // --------- erase
    m.erase("vedant");
    cout << "erase: " << endl;
    cout << "count of vedant after erase: " << m.count("vedant") << endl;

    // --------- printing
    cout << endl;
    cout << "printing map: " << endl;
    for (auto i : m)
    {
        cout << i.first << " - " << i.second << endl;
    }

    cout << endl;
    // using iterators
    cout << "printing using iterators: " << endl;
    unordered_map<string, int>::iterator i = m.begin();

    while (i != m.end())
    {
        cout << i->first << " - " << i->second << endl;
        i++;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{

    unordered_map<string, int> m;

    cout << m["vedant"] << endl;
    cout << m.at("vedant") << endl;

    cout << m.at("bothikar") << endl;
    cout << m["bothikar"] << endl;

    return 0;
}

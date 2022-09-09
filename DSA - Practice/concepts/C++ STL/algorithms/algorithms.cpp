#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> v)
{
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    cout << "----------ALGORITHMS----------" << endl;

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    // this only checks if the element exists or not
    // if exists: returns 1
    // else: returns 0
    cout << "BINARY SEARCH: " << binary_search(v.begin(), v.end(), 99) << endl;

    int a = 5, b = 6;

    cout << "MAX: " << max(3, 4) << endl;
    cout << "MIN: " << min(3, 4) << endl;
    cout << "SWAP: " << endl;
    swap(a, b);

    // reverse a string
    string s = "vedant";
    reverse(s.begin(), s.end());
    cout << s << endl;

    // rotate
    vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9};

    int rot = 2;
    //rotate left
    rotate(v1.begin(), v1.begin() + rot, v1.end()); //vector: 3 4 5 6 7 8 9 1 2
    cout << "ROTATE: " << endl;
    printVector(v1);

    cout << "----------------SORT: --------" << endl;
    cout << "Before sorting: " << endl;
    printVector(v1);

    // uses INTRO Sort
    sort(v1.begin(), v1.end());
    cout << "After sorting: " << endl;
    printVector(v1);

    return 0;
}
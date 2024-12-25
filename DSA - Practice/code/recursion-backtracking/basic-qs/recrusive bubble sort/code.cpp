#include <bits/stdc++.h>
using namespace std;

void bubblesort(vector<int> &v, int n)
{

    // base case
    // when size is 0 or 1, it is already sorted

    if (n == 0 || n == 1)
    {
        return;
    }

    // solve for a single case
    // rest all will be handled by recursion

    // this loop places largest element in the end of the array
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] > v[i + 1])
        {
            swap(v[i], v[i + 1]);
        }
    }

    bubblesort(v, n - 1);
}

int main()
{
    int n;
    vector<int> v;

    cout << "enter length of vector: " << endl;
    cin >> n;

    cout << "enter elements in the vector: " << endl;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        v.push_back(input);
    }

    bubblesort(v, n);

    cout << endl;
    // print vector
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    cout << endl;

    return 0;
}
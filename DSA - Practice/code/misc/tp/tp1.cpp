#include <bits/stdc++.h>
using namespace std;

void printCharArr(char ch[], int size)
{

    cout << endl;

    for (int i = 0; i < size; i++)
    {
        cout << ch[i] << " ";
    }

    cout << endl;
}

void printIntArr(int arr[], int size)
{
    cout << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void changeArr(int arr[])
{

    int *ptr = arr;

    ptr[1] = 100;
}

int main()
{

    unordered_map<string, int> m;

    cout << m["vedant"] << endl;
    cout << m.at("vedant") << endl;

    cout << m.at("bothikar") << endl;
    cout << m["bothikar"] << endl;

    return 0;
}

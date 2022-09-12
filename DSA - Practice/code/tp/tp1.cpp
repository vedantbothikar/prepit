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

    int count = 12;
    string str = to_string(count);

    for (int i = 0; i < str.length(); i++)
    {
        cout << str[i] << " - ";
    }
    cout << endl;

    return 0;
}

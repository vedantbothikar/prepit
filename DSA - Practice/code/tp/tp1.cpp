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

    char ch[5] = {'a', 'b'};

    int size = sizeof(ch) / sizeof(char);

    // printCharArr(ch, size);

    int arr[5] = {1, 2};

    int sizeint = sizeof(ch) / sizeof(char);

    changeArr(arr);

    printIntArr(arr, sizeint);

    int a = 3;

    return 0;
}

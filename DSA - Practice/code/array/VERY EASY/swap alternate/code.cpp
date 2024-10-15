#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size)
{

    cout << "Printing array" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void swapAlternate(int arr[], int size)
{

    for (int i = 0; i < size - 1; i = i + 2)
    {
        swap(arr[i], arr[i + 1]);
    }
}

int main()
{

    int size;
    cin >> size;

    int arr[100];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    printArray(arr, size);
    swapAlternate(arr, size);
    printArray(arr, size);

    return 0;
}
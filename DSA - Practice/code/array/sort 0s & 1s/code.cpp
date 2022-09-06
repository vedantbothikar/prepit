#include <bits/stdc++.h>
using namespace std;

// 2*O(n)

void printIntArray(int arr[], int size)
{
    cout << "Printing Array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int countZeroes(int arr[], int n)
{

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count++;
        }
    }

    return count;
}

void segregate(int arr[], int n, int count)
{

    for (int i = 0; i < count; i++)
    {
        arr[i] = 0;
    }

    for (int i = count; i < n; i++)
    {
        arr[i] = 1;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int count = countZeroes(arr, n);
    segregate(arr, n, count);
    printIntArray(arr, n);

    return 0;
}
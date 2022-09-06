#include <bits/stdc++.h>
using namespace std;

// 2 POINTER TECHNIQUE
// O(n)

void printIntArray(int arr[], int size)
{
    cout << "Printing Array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void segregate(int arr[], int n)
{

    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        if (arr[i] == 0 && arr[j] == 1)
        {
            i++;
            j--;
        }
        else if (arr[i] == 0 && arr[j] == 0)
        {
            i++;
        }
        else if (arr[i] == 1 && arr[j] == 0)
        {
            swap(arr[i], arr[j]);
        }
        else if (arr[i] == 1 && arr[j] == 0)
        {
            j--;
        }
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

    segregate(arr, n);
    printIntArray(arr, n);

    return 0;
}
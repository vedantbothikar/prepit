#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE

int findUnique(int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        count = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }

        if (count == 1)
        {
            return arr[i];
        }
    }

    return 0;
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

    cout << findUnique(arr, size);

    return 0;
}
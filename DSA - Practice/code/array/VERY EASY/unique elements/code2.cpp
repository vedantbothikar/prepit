#include <bits/stdc++.h>
using namespace std;

// BETTER APPROACH

int findUnique(int arr[], int size)
{
    // XOR every element
    // so duplicates will be removed & only
    //the unique element will remain

    int ans = arr[0];
    for (int i = 1; i < size; i++)
    {
        ans = ans ^ arr[i];
    }

    return ans;
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
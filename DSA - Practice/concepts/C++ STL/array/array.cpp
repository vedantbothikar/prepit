#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size;

    // Arrays

    // 5 is the size of array
    array<int, 5> arr = {1, 2, 3, 4, 5};

    // size
    size = arr.size();
    cout << "Size: " << size << endl;

    // can access using square brackets
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // accessing at specific index
    // `at`
    // here we have to use parenthesis
    cout << "Element at 2nd index " << arr.at(2) << endl;

    // check if the array is empty or not
    cout << "Check if array is empty or not: " << arr.empty() << endl;

    // front & back
    cout << "FRONT: first element: " << arr.front() << endl;
    cout << "BACK: last element: " << arr.back() << endl;

    return 0;
}
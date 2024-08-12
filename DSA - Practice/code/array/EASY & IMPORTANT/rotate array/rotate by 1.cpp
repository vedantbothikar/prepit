
/*

PROBLEM: https://www.naukri.com/code360/problems/left-rotate-an-array-by-one_5026278

APPROACH:

We want to shift every element to left
- So we can start the array traversal from index 1
- Store the value of index0 element in a variable
- Copy paste the element value of index 1 to index 0
- Copy paste the element value of index 2 to index 1
- and so on
- At last, copy paste the index0 variable value to the last index position

TC: O(N)
S.C: O(1)

*/


#include <bits/stdc++.h> 
vector<int> rotateArray(vector<int>& arr, int n) {
    // Write your code here.

    int firstElement = arr[0];

    for(int i=1; i<n; i++) {

        arr[i-1] = arr[i];
    }

    arr[n-1] = firstElement;
    return arr;
}

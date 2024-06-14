/*

# APPROACH 1 - Brute Force

Sort the array and choose the last element from the array
- In built sorting function from stl
T.C O(nlogn)

*/

#include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {
    // Write your code here.

    sort(arr.begin(), arr.end());
    return arr[arr.size() - 1];
}   
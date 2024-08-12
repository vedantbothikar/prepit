/*

# APPROACH 1 - BETTER

- Travel through all elements of the array
- Maintain a variable called largest
- Initialize the variable with the first element of the array
- Whenever there is an element greater than largest, then update the variable
- Print largest

TC O(n)

*/

#include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {
    // Write your code here.

    int largest = arr[0];

    for(int i=0; i<arr.size(); i++){


        if(largest < arr[i]){
            largest = arr[i];
        }
    }

    return largest;
}

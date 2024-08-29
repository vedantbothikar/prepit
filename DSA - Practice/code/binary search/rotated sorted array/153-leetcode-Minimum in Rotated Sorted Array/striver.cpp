/*
STRIVER SOLUTION: https://youtu.be/nhEMDKMB44g?si=TpE99FvDKcgijeQd


You have to understand that in the sorted portion of the array,
the lowest element 'COULD' be the answer

but most likely the pivot element or minimum element will be 
in the unsorted portion.

*/

class Solution {
public:
    int findMin(vector<int>& arr) {

        int n = arr.size();
        int start = 0, end = n-1;
        int ans = INT_MAX;

        while(start <= end) {

            int mid = start + (end-start)/2;

            if(arr[mid] <= arr[(n+mid-1)%n] and arr[mid] <= arr[(n+mid+1)%n]) {
                return arr[mid];
            }

            // check if left half is sorted
            else if(arr[start] <= arr[mid]) {
                
                ans = min(ans, arr[start]); // check which one is smaller
                // now start searching in the unsorted portion
                start = mid + 1;
            }
            else {
                // this means right half is sorted

                ans = min(ans, arr[mid]);
                end = mid - 1;  // to continue search in left half (which is unsorted one)
            }
        }

        return ans;
    }
};
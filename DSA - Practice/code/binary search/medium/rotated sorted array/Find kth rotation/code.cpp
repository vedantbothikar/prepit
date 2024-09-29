/*

SOLUTION:
https://youtu.be/jtSiWTPLwd0
*/

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        int ans = INT_MAX;
        int ansInd = -1;
        int start = 0, end = n-1;
        
        while(start <= end) {
            
            int mid = start + (end-start)/2;
            
            if(arr[mid] <= arr[(n+mid-1)%n] and arr[mid] <= arr[(n+mid+1)%n]){
                return mid;
            }
            
            // check if sorted portion is on left
            else if(arr[start] <= arr[mid]) {
                if(arr[start] < ans) {
                    ans = arr[start];
                    ansInd = start;
                }
                start = mid + 1;
            }
            
            // this means right is sorted
            else {
                if(arr[mid] < ans) {
                    ans = arr[mid];
                    ansInd = mid;
                }
                end = mid - 1;
            }
            
        }
        
        return ansInd;
    }
};

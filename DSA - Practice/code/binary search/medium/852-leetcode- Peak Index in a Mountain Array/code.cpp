class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int start = 0, end = arr.size()-1;
        
        while(start <= end) {

            int mid = start + (end-start)/2;

            // handling edge cases
            if(mid == 0) {
                start = mid + 1;
                continue;
            }
            else if (mid == arr.size()-1) {
                end = mid - 1;
                continue;
            }

            // if solution is found
            if(arr[mid] > arr[mid-1] and arr[mid] > arr[mid+1]) {
                return mid;
            }
            else if (arr[mid] > arr[mid-1]) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        
        return -1;
    }
};
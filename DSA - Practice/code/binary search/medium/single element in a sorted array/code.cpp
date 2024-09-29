/*

SOlution: https://www.youtube.com/watch?v=HGtqdzyUJ3k

*/


class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {

        int n = arr.size();
        int start = 0, end = n-1;

        if(n == 1) return arr[0];

        while(start <= end) {

            int mid = start + (end-start)/2;

            // check if there is no duplicate of mid element
            int left = (n + mid - 1) % n;
            int right = (n + mid + 1) % n;
            if(arr[left] != arr[mid] and arr[right] != arr[mid]) {
                return arr[mid];
            }
            
            // Now search in that half where there are odd no. of elements after NOT considering the pair of mid element

            int leftSize = arr[left] == arr[mid] ? mid - 1 : mid;
            if(leftSize%2) { // if leftSize is odd
                end = mid - 1;  // search in left size
            }
            else {
                start = mid + 1;
            }
        }
        
        return -1;
    }
};
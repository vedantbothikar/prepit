class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {

        int n = arr.size();
        int start = 0;
        int end = n - 1;
        int startIndex = -1;

        // similar to finding lower bound of an element
        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (arr[mid] == target) {
                startIndex = mid;
                end = mid - 1;
            } else if (arr[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        // but we need to check if the index element value is equal to target,
        // if not, then the element does not exist in the array
        if (startIndex == -1) {
            return {-1, -1};
        }

        // now that we have the first index of the occurrence of the element, we
        // will find the index of the last occurrence

        start = 0;
        end = n - 1;
        int lastIndex = -1;

        // similar to finding lower bound of an element
        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (arr[mid] == target) {
                lastIndex = mid;
                start = mid + 1;
            } else if (arr[mid] > target) {
                end = mid - 1;
            }

            else {
                start = mid + 1;
            }
        }

        return {startIndex, lastIndex};
    }
};
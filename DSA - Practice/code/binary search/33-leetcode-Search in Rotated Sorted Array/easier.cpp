/*
PROBLEM: https://leetcode.com/problems/search-in-rotated-sorted-array/description/
SOLUTION: https://youtu.be/5qGrJbHhqFs?si=0sr1CrBC6icNOJws
*/


/*

While solving, you need to observe that it is guaranteed that one half of the array will be sorted always.

7 8 9 1 2 3 4 5
here mid is equal to 1
and the mid to last section (right side) will be sorted but the left side portion is not sorted


*/

/*

APPROACH:

binary search: start, mid, end

while start <= end
    mid = ...

    if arr[mid] == target -> return mid;

    // here we will check if the left half is sorted, if yes then we will check if the target is in the left, or else we will start the next iteration searching in the right half (Why are we doing like this? why are we checking which side is sorted? Ans: So, that we can check if our target element exists on the left or right sside... because let's say the left side is sorted then we can proprly check if the target is present on the left side or not by comparing it with the extreme elements of that half, but we cannot do that with the other half because that will be unsorted...)
    else if (arr[start] < arr[mid]){

        // check if the target is present on left half
        if(arr[start] <= target and target <= arr[mid]) {
            // check on left half
            end = mid - 1
        }
        else {
            // check on right side
            start = mid - 1
        }
    }

    else {
        // right side is sorted

        // check if target is present on right side
        if(arr[mid] <= target and target <= arr[end]) {
            // check on right half
            start = mid + 1
        }
        else {
            // check on left half
            end = mid - 1
        }
    }

    return -1 // when the element does not exist in the array


*/


class Solution {
public:
    int search(vector<int>& arr, int target) {
        
        int start = 0, end = arr.size()-1;

        while(start <= end) {

            int mid = start + (end - start) / 2;

            if(arr[mid] == target) {
                return mid;
            }
            // check if left half is sorted
            else if(arr[start] <= arr[mid]) {
                
                // check if target is present in left half
                if(arr[start] <= target and target <= arr[mid]) {
                    end = mid - 1;
                }
                else {  // this means target is in right half
                    start = mid + 1;
                }
            }
            else {  // this means right half is sorted

                // check if target is present in right half
                if(arr[mid] <= target and target <= arr[end]) {
                    start = mid + 1;
                }
                else {  // this means target is in left half
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};
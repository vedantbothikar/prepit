/*

Striver Solution: https://www.youtube.com/watch?v=tp8JIuCXBaU&ab_channel=takeUforward

OPTIMAL SOLUTION:

Three pointer approach
We will keep 3 pointers: low, mid, and high

- low: will point to the position where if 0 is encountered ahead, then the place where 0 is to be swapped with
- mid: this we will use to go ahead and traverse...
- high: place where 2 is to be placed if encountered



3 CASES:

If arr[mid] == 0
- swap(arr[low], arr[mid])
- low++  and   mid++

If arr[mid] == 1
- mid++


If arr[mid] == 2
- swap(arr[mid], arr[high])
- high--
NOTE: here we are not incrementing mid because the element at high is unsorted one



*/



class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();
        int low = 0, mid = 0;
        int high = n-1;


        while(mid <= high) {

            if(nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }

            else if(nums[mid] == 1) {
                mid++;
            }

            else if(nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
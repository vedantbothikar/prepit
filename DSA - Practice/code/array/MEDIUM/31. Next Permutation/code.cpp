/*

- https://leetcode.com/problems/next-permutation/

Read the optimal solution here:
- https://takeuforward.org/data-structure/next_permutation-find-next-lexicographically-greater-permutation/

From the right side of array Find the first value that is smaller than the next element

Step 1: find the break point
Step 2: if the break point does not exist, that means we are at the last permutation already. So retur a sorted array (which is basically just the reverse of what we currently have)

// now suppose we have the break point
Step 3: Now replace the breakpoint value with the smallest value which is greater than the breakpoint value and lies in the right side of it. But since the right side will be in the descending order, we just come traversing from the right side and whichever element apears first, and greater than the breakpoint value, we will swap them

Step 4: Now we want the right side of breakpoint to be in the sorted order since we want that right side to be in its first permutation. For this we need to sort them. But since the right side is already is descending order, we just need to reverse the elements and we will get the ascending sorted order of elements.


TC: O(n)
SC: O(1)

*/
class Solution {

    void swapNextGreaterInd(vector<int>& nums, int breakpointInd) {

        int n = nums.size();
        for(int i = n-1; i > breakpointInd; i--) {
            
            if(nums[i] > nums[breakpointInd]) {
                
                swap(nums[i], nums[breakpointInd]);
                return;
            }
        }
    }

    int breakpointInd(vector<int>& nums) {

        int n = nums.size();
        for(int i = n-2; i >= 0; i--) {

            if(nums[i] < nums[i+1]) {

                return i;
            }
        }

        return -1;
    }

public:
    void nextPermutation(vector<int>& nums) {
        
        // Step 1
        int bpInd = breakpointInd(nums);

        // Step 2: if nums in descending order: (already at last permutation)
        if(bpInd == -1) {

            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Replace breakpoint with next greater
        swapNextGreaterInd(nums, bpInd);

        // Step 4: reverse right side of breakpointInd
        reverse(nums.begin() + bpInd+1, nums.end());
    }
};
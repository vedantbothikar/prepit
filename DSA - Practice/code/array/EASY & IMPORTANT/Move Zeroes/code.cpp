/*
PROBLEM: https://leetcode.com/problems/move-zeroes/description/

# Intuition

Because it is mentioned that copy of the array cannot be made, then 
2 pointer approach could be used.

One pointer can be used to traverse the array while the second one to maintain
the position of exactly where the next element is to be copy-pasted.

# Approach

pointers: i,j 
i: traverse the array
j: location where the element is to be updated
count: keeps a count of number of zeroes in the array

- Traverse the array in loop
- If the current element is zero
    - count++
    - if count was increased for the first time, then make j point to i (j = i)
- Else 
    - copy the value of current element to the jth position
    - j++

- At the end of the loop
    - start another loop from size-count to size 
    - in this loop, make all element values to 0
# Complexity
- Time complexity: O(N)
- Space complexity: O(1)



*/


class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int j = -1;
        int count = 0;

        for(int i=0; i<nums.size(); i++) {

            if(nums[i] == 0) {

                if(count == 0) {    // This is to initialize j to the correct index

                    j = i;
                }

                count++;    
            }
            else {

                if(j == -1) {   // CASE: example input is: [1]. So, if first element is non-zero, to avoid index access error
                    j = i;
                }

                nums[j] = nums[i];
                j++;
            }
        }

        // Append count number of zeroes at the end
        for(int i=nums.size()-count; i<nums.size(); i++) {

            nums[i] = 0;
        }
    }
};
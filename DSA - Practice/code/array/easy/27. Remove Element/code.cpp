/*

- https://leetcode.com/problems/remove-element/description/

NOTE:
- order does not matter
- return k
- do in place shifting

so I can simplify the problem to something like:

- shift all vals to the end of the array
OR
all of the elements should be non-val elements

-------

[0,1,3,0,4,0,4,2]
           i   ^

LOGIC:
note: maintain a pointer valptr let's say. This will point to the place where we should replace the element with a non-val element

valptr = 0
i = 0

- traverse the array
- if(arr[i] == val)
    - skip the element and go to next (i++)
- else (non val)
    - replace the element at i with the element at valptr

the value of k will be: i-1


*/
class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
    
            int n = nums.size();
            int valptr = 0;
            int index = 0;
    
            while(index < n) {
                
                int curr = nums[index];
                if(nums[index] != val) {
                    nums[valptr] = nums[index];
                    index++;
                    valptr++;
                }
                else {
                    index++;
                }
            }
    
            return valptr;
        }
    };
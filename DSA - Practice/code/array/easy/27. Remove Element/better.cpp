/*

- READ: https://gist.github.com/vedantbothikar/1b42d0c544f9502a081a656f3b6f414b


IMP:
The index++ line MUST be inside the else condition block.
If you keep it without the else condition it will NOT work.

# REASON:

Take this example:

nums = 
[3,2,2,3]

val =
3

If we consider index = 0 initially,
then since there is a match of nums[index] and val
we swap the last element and the nums[index] which is the first element.
Now because the last element also was a 3, if we go ahead and do index++, then we will ignore/miss this new 3.
So we should not go ahead. We should keep checking at the same position until the element at the current position is NOT val.




*/
class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
    
            int n = nums.size();
    
            int index = 0;
    
            while(index < n) {
    
    
                if(nums[index] == val) {
                    
                    nums[index] = nums[n-1];
                    n--;
                }
                else {
                    index++;
                }
            }
            
            return n;
        }
    };
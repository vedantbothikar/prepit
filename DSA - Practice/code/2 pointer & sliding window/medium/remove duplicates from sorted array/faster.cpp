/*

# APPROACH - Using 2 pointers technique. 
- Traverse through all elements of the vector
- Whenever a duplicate element is found, do nothing
- Whenever a unique element is found, copy the value of this unique element to the locationPointer  
    which will be pointing to the location where first duplicate element was found
- keep one pointer to the element which will be updated (usually the duplicate element which needs to be purged)
- keep another pointer for traversing through the vector



*/


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int current = nums[0];
        int locPointer = 1; 

        for(int i=1; i<nums.size(); i++) {

            // if unique element
            if(current != nums[i]) {
                                
                nums[locPointer] = nums[i];
                locPointer++;   // go to the position where the unique element will be copied
                current = nums[i];  // update current to check new duplicates
            }
        }

        return locPointer;
    }
};













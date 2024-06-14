/*

BRUTE FORCE APPROACH - O(N^2)

# APPROACH
- We will maintain a variable called current
- Before traversing the first element will be assigned to current
- Start loop from i=1 to lastElement
- if the element is equal to current then erase the element from the vector
- else update current to the latest element of the vector


# HOW TO USE Inbuilt erase function:

- Remove element at position 2 (third element, which is 3)
    vec.erase(vec.begin() + 2);
Notes
- The erase method takes an iterator as an argument, so you use vec.begin() + position to specify the position of the element to remove.
- Removing an element from the vector shifts all the subsequent elements to the left, which changes their positions.
- The time complexity of the erase operation is linear (O(n)) because all elements after the removed element need to be shifted.


Because we are looping through all elements and then inside that loop,
we are using erase method which inturn uses O(N)
Then the overall complexity will be O(N^2)
So, to reduce this, we can use 2 pointer technique as below


# Alternative of inbuilt erase method => using 2 pointers technique. 

- keep one pointer to the element which will be updated (usually the duplicate element which needs to be purged)
- keep another pointer for traversing through the vector



*/


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int current = nums[0];

        for(int i=1; i<nums.size(); i++) {

            if(current == nums[i]) {
                nums.erase(nums.begin() + i);
                --i;    // reset index, because we deleted an element
            }
            else {
                current = nums[i];
            }
        }

        return nums.size();
    }
};


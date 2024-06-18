/*

PROBLEM: https://leetcode.com/problems/rotate-array/


Observation:
Because we want to shift the array by a particular number ahead, (k), so each and every element will shift
to the right side by k

Assume: nums = [1,2,3,4,5,6,7], k = 3

So,
0th index element goes to 3rd index
1st index element goes to 4th index
2nd index element goes to 5th index
3rd index element goes to 6th index

But when we try to shift the 5th position element it cannot be shifted to 8th position because the size of 
the array is limited 

So, we use the mathematical relation:

newIndex = (oldIndex + k) % sizeOfArray

Trying this equation for oldIndex = 4 and k = 3 and sizeOfArray = 7
newIndex = (4 + 3) % 7 = 0

for next element
newIndex = (5 + 3) % 7 = 1

And so on...


APPROACH:

- Create a duplicate of the og array
- Loop through the duplicate array
- For every index of array - apply the mathematical formula and calculate the newIndex
- In the ogArray - change the value at newIndex to the currentIndex value of duplicateArray


COMPLEXITY:
TC: O(N)
SC: O(N)


*/

class Solution {
public:

    int calculateNewIndex(int oldIndex, int rotation, int sizeOfArray) {

        return (oldIndex + rotation) % sizeOfArray;
    }

    void rotate(vector<int>& nums, int k) {

        vector<int> duplicate = nums;

        for(int i=0; i<duplicate.size(); i++) {

            int newIndex = calculateNewIndex(i, k, duplicate.size());
            nums[newIndex] = duplicate[i];
        }
    }
};
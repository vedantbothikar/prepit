/*

- https://leetcode.com/problems/find-the-duplicate-number/
Watch video: https://neetcode.io/solutions/find-the-duplicate-number


This solution is not so intuitive and it is preferred to REMEMBER it rather than finding the logic for the last part of it.

We are going to solve this problem using linkedlist

Now what we will do is that since it is mentioned that the values are between 1,n we are goign to use this. The values we will be using as the pointers to next nodes.
         
        [1,3,4,2,2]
         ^ ^ ^ ^ ^ 
index:   0 1 2 3 4
For example, if we start at index 0, the value is 1, so we go to index 1, where value is 3 so we go to index 3, where value is 2, where value is 2 so we go to index 2, where value is 4, so we go to index 4 where value is 2, so we go to index 2 where value is 4... and so on...
If you observe we reach a loop BECAUSE one of the digits is repeated. Now since there will always be a repeated digit as per the question, there will always be a loop.

Now, to traverse the loop we will use the FLoyd's algorith of slow and fast pointers.

Here comes the part that you need to REMEMBER:
Wherever the slow and fast pointers meet (lets call this point B)
And the point from where we start our floyd alogirhtm, like in this case we were starting the traversal from the index 0.
So let's call that point as A


Now as per this new rule that you have to remember:
The distance of the repeated value from both A and B is the SAME. 


So, to find the repeated value, just keep 2 pointers from A and B locations, and traverse until the 2 pointers meet (because the repeated value is at same distance from both of them)
Whenever they meet at a point, return that point

TC: O(n)
SC: O(1)

*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // we are starting from 0th index
        int slow = 0;
        int fast = 0;
        while(true) {

            slow = nums[slow];
            
            fast = nums[fast];  
            fast = nums[fast];  // for fast we need to traverse double, so twice

            if(slow == fast) {
                break;
            }
        }

        // A is 0 since we started from 0th index
        int A = 0;

        // B is where the slow and fast had met 
        int B = slow;
        
        // check where A and B meet each other
        while(true) {

            A = nums[A];
            B = nums[B];

            if(A == B) {
                return A;
            }
        }

        // we will never reach here
        return -1;
    }
};
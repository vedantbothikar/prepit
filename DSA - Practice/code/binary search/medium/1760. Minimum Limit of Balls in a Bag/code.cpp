/*

- https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/
- https://youtu.be/MQlC8EoOdZ0?si=JRjhi3FW_7n1z8XM

Intuition: since qs has both min and max in it, we should think of binary search first.

we know that the max no of balls that could be is the max element in the nums
and the min no of balls will be 1 (since it is mentioned in the qs that the bags will have positive balls)

As the max no of balls we have increases, the maxoperations decreases

We need to find the min value of the max no of balls we can have 
So our answer will lie somewhere between 1 to the max element of the array

So we can do a search in this range, and we will search that if any of the elements (which is actually the max no of balls we will consider we can have) we will check if having those max no of balls is possible or not, using maxOperations

How to check if it is possible or not?
- We can divide each num of balls with the maxBalls and check how many operations it will need

For example,
nums = [2,4,8,2]
maxOperations = 4
If we want our maxballs to be 7, then 
(2 / 7 = 0) + (4/7=0) + (8/7=1) + (2/7=0) = 1
So total 1 operations will be required, that means our this answer is valid.
But there could be a better answer,
so check for 6 similarly,
similarly then check for 5, and keep reducing until the ans stays valid.

Note: if maxballs perfectly divides the num, then we need to reduced the currOps by 1
Why? example: if num = 12 and maxballs that we want to keep is 6,
then 12/6 =2 But actually we only need to split the bag once. So ans should be reduced by 1


TC: O(n * logk)
k: max element in the nums array
n: length of nums array

SC: O(1)

*/
class Solution {

    bool isPossibleAns(int maxNoOfBalls, vector<int>& nums, int maxOps) {

        int currOps = 0;
        for(int num : nums) {

            currOps += (num / maxNoOfBalls);

            // if perfectly divisible
            if(num % maxNoOfBalls == 0) currOps--;

            if(currOps > maxOps) return false;
        }

        return true;
    }

public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int start = 1;
        int end = *max_element(nums.begin(), nums.end());
        int ans = -1;

        while(start <= end) {

            int mid = start + (end-start)/2;

            if(isPossibleAns(mid, nums, maxOperations)) {
                
                // store ans and search left
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return ans;
    }
};
/*

Striver solution: 
https://www.youtube.com/watch?v=w_KEocd__20&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=6&ab_channel=takeUforward

BRUTE FORCE:
- We can apply two loops and solve it in O(N^2)
- i and j pointers will be used and we will keep finding the sum of every subarray and then return the max


OPTIMAL:
KADANE's ALGORITHM

- We keep summing the array elements as long as the sum stays positive
- Whenever the sum becomes negative that is of no use to us, so we initialize sum back to 0

TC: O(N)
SC: O(1)


*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum = 0;
        int maxAns = INT_MIN;
        for(int num : nums) {

            sum += num;
            maxAns = max(sum, maxAns); 

            if(sum < 0) sum = 0;
        }

        return maxAns;
    }
};
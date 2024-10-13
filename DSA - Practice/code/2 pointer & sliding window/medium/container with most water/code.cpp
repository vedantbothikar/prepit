/*

- https://leetcode.com/problems/container-with-most-water/


Brute force approach:

O(n^2)
start traversing from 0 to end
    for i+1 to end
        calculate the water and keep updting if it exceeds maxWater


BETTER: O(N)
2 pointers

start and end
move inwards and keep shifting only the pointer that is smaller compared to the other one (because shifting the larger one would not make sense since we will reduce the water it could hold. We shift the smaller pointer inward with the hope that we nuggt get something in the future)

How to calculate water?
the water level would be determined by the smaller pointer
waterAmount = smallPointer * (end-start)


*/

class Solution {
public:
    int maxArea(vector<int>& height) {

        int n = height.size();
        int start = 0, end = n-1;

        // base case when n == 2
        if(n == 2) return min(height[0], height[1]);

        int maxWater = INT_MIN;

        while(start < end) {

            int smallerPointer = min(height[start], height[end]);
            int waterAmount = smallerPointer * (end - start);

            maxWater = max(maxWater, waterAmount);

            if(height[start] < height[end]) {
                start++;
            }
            else {
                end--;
            }
        }

        return maxWater;
    }
};
/*

Watch
- https://youtu.be/ZI2z5pq0TqA?si=7hLz4XzNu8glkrA1&t=660

Using 2 pointers

We will track the min of the maxes from right and left

Note: remember that no water can ever be stored on the endpoints (corners)

Time complexity: O(n)
Space complexity: O(1)

*/
class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        int l = 0;
        int r = n-1;
        
        int leftMax = height[0];
        int rightMax = height[n-1];

        int totalWater = 0;
        while(l < r) {

            if(leftMax < rightMax) {

                l++; 
                leftMax = max(leftMax, height[l]);
                totalWater += leftMax - height[l];
            }
            else {
                
                r--;
                rightMax = max(rightMax, height[r]);
                totalWater += rightMax - height[r];
            }
        }

        return totalWater;
    }
};
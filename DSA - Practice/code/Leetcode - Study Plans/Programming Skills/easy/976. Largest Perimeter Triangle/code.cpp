/*

- https://leetcode.com/problems/largest-perimeter-triangle/submissions/1496991391/?envType=study-plan-v2&envId=programming-skills


Remember the property of triangle that the sum of any two sides MUST be STRICTLY greater than the len of the 3rd side.

So since we have to find the largest perimeter, we need to check largest sides first (so sort the array)

and from the end check if any 3 sides follow the triangle property, then return 
(And we dont need to check this property for every 2 sides, we can only check if the sum of the 2 smaller sides is greater than the largest side, the reason is that if the sum of 2 smaller sides is greater than the largest side, the other checks will satisfy always)


*/
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        
        int n = nums.size();

        // sort
        sort(nums.begin(), nums.end());

        for(int i = n-3; i >= 0; i--) {

            if(nums[i] + nums[i+1] > nums[i+2]) {
                return nums[i] + nums[i+1] + nums[i+2];
            }
        }

        return 0;
    }
};
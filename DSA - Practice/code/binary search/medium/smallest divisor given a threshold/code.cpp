/*

- problem: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

Observation:
since dividing by the largest number in the array makes all values to 1
that means sum of all values when divided largest will be the smallest threshold 

and suppose we divide every element by 1, then the sum after divinding will be the largest. 

So as we take smaller divisor, we get larger threshold, as take larger divisor, we get smaller threshold.
So, we can apply binary search on a range from 1 to the largest number in the given array


Questions:
- How to find the largest number from the array efficiently? (CPP STL)
- We will need to create a helper function for calculating the sum of all numbers of the array when divided by a particular number (when mid of array needs to be checked if that is the answer)


*/


class Solution {

    int compute(vector<int>& nums, int divisor) {

        int sum = 0;
        // divide every num with divisor and return the sum
        for(int i = 0; i < nums.size(); i++) {

            sum += (nums[i] + divisor - 1) / divisor;   // divide nums[i] by divisor in such a way that we get the ceil of it
        }

        return sum;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {

        // find the max element
        auto largestTemp = max_element(nums.begin(), nums.end());
        int largest = *largestTemp;

        // apply binary search on a range of 1 to *largest
        int start = 1;
        int end = largest;

        while(start <= end) {

            int mid = start + (end - start)/2;

            if(compute(nums, mid) <= threshold) {  // we found an answer, now keep finding a smaller answer, by going to left

                end = mid - 1;
            }
            else {  // answer not found yet, go right
                start = mid + 1;
            }
        }

        return start;
    }
};
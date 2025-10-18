// Problem Link: https://leetcode.com/problems/maximum-difference-between-increasing-elements/
/*

Title: 2016. Maximum Difference Between Increasing Elements

Problem Description:
Given an integer array nums, find the maximum difference between two elements such that the larger element appears after the smaller element. If no such difference exists, return -1.


*/


class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        
        int n = nums.size();
        int maxDiff = INT_MIN;
        int smallest = INT_MAX;

        for(int i = 0; i < n; i++) {
            
            smallest = min(smallest, nums[i]);

            if(smallest < nums[i]) {

                int currDiff = nums[i] - smallest;
                maxDiff = max(maxDiff, currDiff);
            }
        }

        if(maxDiff == INT_MIN) return -1;

        return maxDiff;
    }
};
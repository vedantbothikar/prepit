/*

- https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&leftPanelTabValue=PROBLEM
- https://takeuforward.org/data-structure/longest-subarray-with-given-sum-k/

NOTE: this solution will only work for positive integers
For this to work with negative integers as well, check other solution.
It will not work for negatives because of the inner while loop and its conditions

TC: O(n)

*/


int longestSubarrayWithSumK(vector<int> arr, long long target) {
        int n = arr.size();
        int maxLen = 0;
        long long currSum = 0;
        
        int left = 0;
        int right = 0;
        
        while(right < n) {
            
            currSum += arr[right];
            
            // decrement left if sum > target
            while(left <= right && currSum > target) {
                
                currSum -= arr[left];
                left++;
            }
            
            if(currSum == target) {
                
                maxLen = max(maxLen, right-left+1);
            }
            
            // increment right
            right++;
        }
        
        return maxLen;
}
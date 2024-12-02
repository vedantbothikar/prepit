/*

This is the better solution (not optimal)

Map is storing the sum of the elements till that index

- https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-sub-array-with-sum-k
Watch this video (watch the better solution in that)
- https://www.youtube.com/watch?v=frf7qxiN2qU&ab_channel=takeUforward


// Here we are taking extra space compared to other
TC: O(n)
SC: O(n)
*/


using ll = long long;
class Solution {
  public:
    int lenOfLongestSubarr(vector<int>& nums, int target) {
        // code here
        
        
        int n = nums.size();
        unordered_map<ll, int> mp;
        int maxLen = 0;
        ll sum = 0;

        for(int i = 0; i < n; i++) {

            sum += nums[i];

            if(sum == target) {

                maxLen = max(maxLen, i+1);
            }

            ll remaining = sum - target;
            // check if remaining DOES exist in map
            if(mp.find(remaining) != mp.end()) {

                int subArrLen = i - mp[remaining];
                maxLen = max(maxLen, subArrLen);
            }
            
            // add only if sum does NOT exist in map
            // this is being done to handle zeroes
            if(mp.find(sum) == mp.end()) {
                
                mp[sum] = i;
            }
        }

        return maxLen;
    }
};
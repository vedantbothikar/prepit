/*
- https://leetcode.com/problems/max-consecutive-ones-iii/description/

swap 0s with 1s to make the longest substring

left = 0
right = 0 to n

if the element is 0, then you replace it with 1
max is k such replacements

if the current num is 1, keep going
else 
    if replaced < k
        replced++
    else 
        slide the window

slide the window means, left will increase until a point where it has to be replaced,
so that on replacement will reduce
    - so run a loop for this

*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size();
        int maxLen = INT_MIN;

        int replaced = 0;
        int left = 0;
        for(int right = 0; right < n; right++) {

            if(nums[right] == 1) {

                // check maxLen 
                maxLen = max(maxLen, right - left + 1);
            } 
            else {  // it means nums is 0

                if(replaced + 1 <= k)    // check if we update replaced now, it shouldn't exceed 
                {
                    replaced++;
                }
                else {  // slide the window
                    
                    while(left <= right and replaced == k) {
                        
                        if(nums[left] == 0) {
                            replaced--;
                        }

                        left++;
                    }

                    replaced++;
                }
       
                maxLen = max(maxLen, right - left + 1);
            }
        }
        
        return maxLen;
    }
};
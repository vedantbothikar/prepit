/*

2 pointers:
- one for positive: starts from 0
- one for negaitve: starts from 1


vector<int> ans(n, -1);

Whenever you find first positive, add in positive element position, then increment positive element pointer by 2
and do similar for negative as well

TC: O(n)
SC: O(n)

*/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size();

        int pos = 0;
        int neg = 1;

        vector<int> ans(n, -1);

        for(int i = 0; i < n; i++) {

            // positive
            if(nums[i] > 0) {

                ans[pos] = nums[i];
                pos += 2;
            }
            else {
                // negative

                ans[neg] = nums[i];
                neg += 2;
            }
        }

        return ans;
    }
};
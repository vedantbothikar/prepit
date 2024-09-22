class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();
        int l = 0, r = 0;
        int farthest = 0;
        int jumps = 0;

        while(r < n-1) {    // condition when we reach the end

            for(int i = l; i <= r; i++) {   // for every element in l to r
                
                farthest = max(farthest, i + nums[i]);
            }

            // update pointers
            l = r + 1;
            r = farthest;

            jumps++;
        }

        return jumps;        
    }
};
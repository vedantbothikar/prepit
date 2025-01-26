/*

- watch and understand neetcode video
    - https://neetcode.io/solutions/3sum

1 -> because as soon as we start with position nums we know there wont be any solution ahead

*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break; // (1)
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // below is the approach of Two Sum - 2 approach
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0) {
                    r--;
                } 
                else if (sum < 0) {
                    l++;
                } 
                else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;

                    // skip duplicates only from one side (watch neetcode video)
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                }
            }
        }
        return res;
    }
};
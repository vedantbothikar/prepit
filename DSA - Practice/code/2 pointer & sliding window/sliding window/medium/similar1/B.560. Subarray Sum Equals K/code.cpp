using ll = long long;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n = nums.size();

        // map <sum, count>: count will store the no of occurrences of this sum
        unordered_map<ll, int> mp;
        int count = 0;
        ll sum = 0;

        for(int i = 0; i < n; i++) {

            sum += nums[i];

            if(sum == k) {
                
                count++;
            }

            ll remaining = sum - k;
            // if remaining is found in the map
            if(mp.find(remaining) != mp.end()) {
                
                count += mp[remaining];
            }

            mp[sum]++;
        }

        return count;
    }
};
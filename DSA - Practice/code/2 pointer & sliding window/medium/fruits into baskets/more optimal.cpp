/*
- https://leetcode.com/problems/fruit-into-baskets/description/
- https://youtu.be/e3bs0uA1NhQ?si=zx92OaZ0v9I8ysn4
*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int n = fruits.size();
        int maxLen = 0, l = 0, r = 0;

        unordered_map<int, int> mp;

        while(r < n) {

            mp[fruits[r]]++;

            if(mp.size() > 2) {

                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0) {
                    mp.erase(fruits[l]);
                }
                l++;
            }
            else {

                maxLen = max(maxLen, r-l+1);
            }

            r++;
        }
        
        return maxLen;
    }
};
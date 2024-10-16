/*

- https://leetcode.com/problems/fruit-into-baskets/

# Complexity
- Time complexity: O(2*N)

- Space complexity: O(1) (Because the size does not go beyond 3 in the map)
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

                while(mp.size() > 2) {

                    mp[fruits[l]]--;
                    if(mp[fruits[l]] == 0) {
                        mp.erase(fruits[l]);
                    }
                    l++;
                }

            }
            else {

                maxLen = max(maxLen, r-l+1);
            }

            r++;
        }
        
        return maxLen;
    }
};
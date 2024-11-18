/*

- https://leetcode.com/problems/daily-temperatures/description/
- Watch: https://youtu.be/cTBiBSnjO3c

TC: O(N)
SC: O(N)

*/


class Solution {

public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        
        int n = temps.size();
        stack<pair<int, int>> s;    // {number, index}
        vector<int> ans(n, 0);

        s.push({temps[0], 0});
        for(int i = 1; i < n; i++) {

            while(!s.empty() && temps[i] > s.top().first) {
                
                pair<int, int> p = s.top();
                ans[p.second] = i - p.second;
                s.pop();
            }

            s.push({temps[i], i});
        }

        return ans;
    }
};
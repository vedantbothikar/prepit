/*
- problem: https://leetcode.com/problems/assign-cookies/
- solution: https://www.youtube.com/watch?v=DIX2p7vb9co

*/


class Solution {
public:
    int findContentChildren(vector<int>& greed, vector<int>& cookie) {
        
        sort(greed.begin(), greed.end());
        sort(cookie.begin(), cookie.end());

        int i = 0, n = greed.size();
        int j = 0, m = cookie.size();

        while(i < n and j < m) {

            if(greed[i] <= cookie[j]) {
                i++;
                j++;
            }
            else {
                j++;
            }
        }

        return i;
    }
};
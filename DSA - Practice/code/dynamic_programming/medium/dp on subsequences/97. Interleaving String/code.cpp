/*

- https://leetcode.com/problems/interleaving-string/description/
- https://neetcode.io/solutions/interleaving-string

combinations: recursion

choices?:
choose from s1 or s2

if you are able to make the target, then return true
to append to currStr => currStr + s1[index1]

// base cases:
index out of bounds
target matched

DP:
ind1 and ind2

Note: we dont need ind3 in the dp. Why?
ind3 is implicitly tied to the combination of ind1 and ind2
ind3 is Always Determined by ind1 and ind2:

The current position in s3 (ind3) is uniquely determined by the positions in s1 (ind1) and s2 (ind2) because:
`ind3=ind1+ind2`
This is because s3 is formed by interleaving s1 and s2, so the total number of characters processed so far is the sum of the characters taken from s1 and s2.


TC: O(n1 * n2)
SC: O(n1 * n2)


*/
class Solution {

    bool solve(string s1, string s2, string s3, string currStr, int ind1, int ind2, int ind3, vector<vector<int>>& dp) {

        // base conditions:
        if(ind3 == s3.size() && ind1 == s1.size() && ind2 == s2.size()) {
            return true;
        }

        // check in dp
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        // choices
        bool opt1 = false, opt2 = false;

        // NOTE: we also need to check if ind1 or ind2 are out of bounds
        if(ind1 < s1.size() && s3[ind3] == s1[ind1]) {

            opt1 = solve(s1, s2, s3, currStr + s1[ind1], ind1+1, ind2, ind3+1, dp);
        }

        if(ind2 < s2.size() && s3[ind3] == s2[ind2]) {

            opt2 = solve(s1, s2, s3, currStr + s2[ind2], ind1, ind2+1, ind3+1, dp);
        }

        return dp[ind1][ind2] = opt1 or opt2;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int n1 = s1.size();
        int n2 = s2.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return solve(s1, s2, s3, "", 0, 0, 0, dp);
    }
};
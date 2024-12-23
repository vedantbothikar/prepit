/*

- https://leetcode.com/problems/edit-distance/
- https://neetcode.io/solutions/edit-distance

combinations
options are:
1. insert
2. delete
3. replace

if word1[ind1] != word2[ind2]
then you can:
insert the word2[ind2]
or 
replace
or 
delete 

if the curr character match, just move ahead and check

base conditions:
if (i1 == w1.size()) return w2.size() - i2;
this means that when i1 reaches end, we have to insert (w2.size() - i2) chars (all chars remaining in the w2) 

if (i2 == w2.size()) return w1.size() - i1;
this means than when we reach the end of w2, we have to delete all the remaining chars of w1


NOTE:
here when we do the 3 operations, we ASSUME to have done those 3 operations without actually modifying the strings


TC: O(n*m)
SC: O(n*m)

*/
class Solution {

    int solve(string w1, string w2, int i1, int i2, vector<vector<int>>& dp) {

        // base conditions
        if (i1 == w1.size()) return w2.size() - i2;
        if (i2 == w2.size()) return w1.size() - i1;

        // check in dp
        if(dp[i1][i2] != -1) return dp[i1][i2];

        // if curr char matches: skip and go to next char
        if(w1[i1] == w2[i2]) {

            return dp[i1][i2] = solve(w1, w2, i1+1, i2+1, dp);
        }

        // try all 3 options
        int ins = 1 + solve(w1, w2, i1, i2+1, dp);
        int del = 1 + solve(w1, w2, i1+1, i2, dp);
        int rep = 1 + solve(w1, w2, i1+1, i2+1, dp);

        return dp[i1][i2] = min(ins, min(del, rep));
    }

public:
    int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(word1, word2, 0, 0, dp);
    }
};
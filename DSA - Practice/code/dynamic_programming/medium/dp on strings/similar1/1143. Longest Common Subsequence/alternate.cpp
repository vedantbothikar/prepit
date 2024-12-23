/*

it is the same way of solving: just that this is 
more intuitive because I am starting from 0,0 index
*/

class Solution {

    int solve(string& text1, string& text2, int index1, int index2, vector<vector<int>>& dp) {

        // base condition: when indices reach ends
        if(index1 >= text1.size() or index2 >= text2.size()) return 0;

        // check in dp
        if(dp[index1][index2] != -1) return dp[index1][index2];

        // logic: possibilities

        int lcs = 0;
        // Case 1: current characters match
        if(text1[index1] == text2[index2]) {

            lcs = 1 + solve(text1, text2, index1+1, index2+1, dp);
        }
        else {  // Case 2: current characters do NOT match

            // we have 2 choices: increase the index of either of the strings: to continue the search

            int option1 = solve(text1, text2, index1+1, index2, dp);
            int option2 = solve(text1, text2, index1, index2+1, dp);
            lcs = max(option1, option2);
        }

        return dp[index1][index2] = lcs;
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int len1 = text1.size();
        int len2 = text2.size();

        vector<vector<int>> dp(len1, vector<int>(len2, -1));
        return solve(text1, text2, 0, 0, dp);
    }
};
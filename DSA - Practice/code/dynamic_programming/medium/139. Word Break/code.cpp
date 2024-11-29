/*
- https://leetcode.com/problems/word-break/submissions/1465400016/
- https://neetcode.io/solutions/word-break

# Approach
For every word we check if it matches the current window of characters in the string

# Complexity
- Time complexity: O(n * m * L)
n: length of input string s
m: number of words in wordDict
L: maximum length of words
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(n)


*/

class Solution {

    bool solve(string& s, vector<string>& wordDict, int index, vector<int>& dp) {

        // base condition
        if(index == s.size()) return true;

        // check in dp
        if(dp[index] != -1) return dp[index];

        // logic: check for every matching word in dictionary
        for(string word : wordDict) {

            int sLen = s.size();
            int wLen = word.size();
            if((index + wLen <= sLen) && (s.substr(index, wLen) == word)) {

                if(solve(s, wordDict, index + wLen, dp)) {
                    dp[index] = 1;
                    return true;
                }
            }

        }

        dp[index] = 0;
        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        vector<int> dp(s.size()+1, -1); // we will use 1 for true and 0 for false
        return solve(s, wordDict, 0, dp);
    }
};
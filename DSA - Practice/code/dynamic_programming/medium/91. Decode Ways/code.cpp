/*

Combinations, so we will use recursion. (Let's think about DP later)
Check all possibilities

What are all possibilities?
- Take single digit (current digit)
- Take double digit (current and next digits) // TODO: handle out of bounds

Base condition:
index == n-1: (and assuming a valid num)
    return 1

# Pseudocode:
recursion:

// base condition
if(!isValid(num)) return 0

if(index == n-1) return 1

// logic: possibilities
int singleDigit = recurse(index+1, s[index])

int doubleDigit = 0
if(index+1 < n) {
    doubleDigit = recurse(index+1, s[index] + s[index+1])
}

return singleDigit + doubleDigit


How to check if a number is valid or not?
Conditions:
- should be of single or double digit only (already handled in logic)
- should be <= 26 and >= 1
- need to handle the case where leading zero:
    - check if the length of the string is 2 and number is < 10: then leading 0: not allowed



TODO:
- DONE: Need a function to check if the current selected number is valid or not
- DONE: Are you handling the case of leading 0


Can we use DP?
- do we have repeating subproblems? Yes:
- 1D DP: based on the index, the dp will store the ans for it

*/
class Solution {

    bool isValidNum(const string& snum) {
        int inum = stoi(snum);
        int slen = snum.size();

        // Check for leading zero
        if (slen > 1 && snum[0] == '0') return false;

        // Check range
        if (inum >= 1 && inum <= 26) return true;

        return false;
    }

    int solve(string& s, int index, vector<int>& dp) {
        // Base condition: Reached the end of the string
        if (index == s.size()) return 1;

        // If the first character is '0', it cannot be decoded
        if (s[index] == '0') return 0;

        // Check memoization
        if (dp[index] != -1) return dp[index];

        // Decode single digit
        int singleDigit = solve(s, index + 1, dp);

        // Decode double digit
        int doubleDigit = 0;
        if (index + 1 < s.size() && isValidNum(s.substr(index, 2))) {
            doubleDigit = solve(s, index + 2, dp);
        }

        // Store the result in dp array
        return dp[index] = singleDigit + doubleDigit;
    }

public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1); // Initialize memoization array
        return solve(s, 0, dp);
    }
};

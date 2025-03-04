/*

2 pointers: start and end
if the chars match, then continue searching to the middle of the string
ELSE:
    if one of the chars do NOT match, 
    CASE1:
        - remove the start char, go ahead by 1, and now check
    CASE2:
        - remove the end char, go ahead by 1, and now check


*/

class Solution {

    bool possiblePalindrome(string &s, int start, int end, bool &removed1Char) {

        // base condition
        if(start >= end) {
            return true;
        }

        if(s[start] == s[end]) {
            return possiblePalindrome(s, start+1, end-1, removed1Char);
        }

        if(removed1Char) return false;

        // chars are not equal
        removed1Char = true;
        bool case1 = possiblePalindrome(s, start+1, end, removed1Char);
        bool case2 = possiblePalindrome(s, start, end-1, removed1Char);

        return case1 or case2;
    }

public:
    bool validPalindrome(string s) {
        

        bool removedChar = false;
        int n = s.size();

        return possiblePalindrome(s, 0, n-1,removedChar);
    }
};
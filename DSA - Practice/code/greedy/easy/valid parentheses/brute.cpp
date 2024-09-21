/*

Problem: https://leetcode.com/problems/valid-parenthesis-string/
Solution: https://youtu.be/cHT6sG_hUZI

METHOD 1:

recursion:

base case:
    if count is negative: 
        - return false

if (
    - we go to next element, and also increment count by 1
else if )
    - goto next element and also decrement count by 1
else // case when *
    - try all 3 options
        - (
        - )
        - blank
    - if any of the options return a true, then return true;

answer will be true when we reach the last element and the count is 0

TC: for this will be O(3^N)
This is because there are 3 options, for the * case
for all those 3 options the recursive calls will be made

This will give TLE

*/

class Solution {

    bool solve(string s, int index, int count) {

        // base case
        if(count < 0) return false;
        if(index >= s.length()) {
            return count == 0 ? true : false;
        }

        // conditions
        if(s[index] == '(') {
            return solve(s, index+1, count+1);
        }
        else if(s[index] == ')') {
            return solve(s, index+1, count-1);
        }
        else {
            // try all 3 options
            bool a = solve(s, index+1, count+1);
            bool b = solve(s, index+1, count-1);
            bool c = solve(s, index+1, count);
            return a or b or c;
        }
    }

public:
    bool checkValidString(string s) {
        
        return solve(s, 0, 0);
    }
};
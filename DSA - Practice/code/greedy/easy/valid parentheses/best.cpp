/*

Problem: https://leetcode.com/problems/valid-parenthesis-string/
Solution: https://youtu.be/cHT6sG_hUZI

METHOD:
Maintain a range: min and max

min cannot go below 0

For every element of string
    if '('
        min++;
        max++;
    else if ')'
        min--;
        max--;
    else
        min--;
        max++;

    if min < 0 {
        min = 0;
    }
    if max < 0 {
        return false;
    }

return min == 0;

at the end we need to check that min should be 0: if yes: return true;



*/


class Solution {
public:
    bool checkValidString(string s) {

        int min = 0, max = 0;

        for(int i = 0; i < s.length(); i++) {

            if(s[i] == '(') {
                min++;
                max++;
            }
            else if(s[i] == ')') {
                min--;
                max--;
            }
            else {
                min--;
                max++;
            }

            if(min < 0) {
                min = 0;
            }
            if(max < 0) {
                return false;
            }
        }
        
        return min == 0;
    }
};
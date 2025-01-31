/*
- https://leetcode.com/problems/valid-number/

*/

class Solution {
public:
    bool isNumber(string s) {

        bool seenNumber = false;
        bool seenExponent = false;
        bool seenDot = false;

        int n = s.size();

        for(int i = 0; i < n; i++) {

            char ch = s[i];

            if(ch >= '0' and ch <= '9') {
                seenNumber = true;
            }
            else if(ch == '-' or ch == '+') {

                if(i > 0) {
                    if(!(s[i-1] == 'e' or s[i-1] == 'E')) {
                        return false;
                    }
                }
            }
            else if(ch == 'e' or ch == 'E') {

                if(seenExponent or !seenNumber) return false;

                seenNumber = false;
                seenExponent = true;
            }
            else if(ch == '.') {

                if(seenExponent or seenDot) return false;
                
                seenDot = true;
            }
            else {
                return false;
            }
        }

        return seenNumber;
    }
};
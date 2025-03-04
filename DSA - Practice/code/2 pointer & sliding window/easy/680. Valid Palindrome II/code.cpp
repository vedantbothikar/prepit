/*

Whenever there's a mismatch, we will perform a normal checkPalindrome

*/

class Solution {

    bool checkPalindrome(string s, int start, int end) {

        while(start <= end) {

            if(s[start] != s[end]) return false;

            start++;
            end--;
        }

        return true;
    }

public:
    bool validPalindrome(string s) {
        
        int n = s.size();

        int start = 0;
        int end = n - 1;


        while(start <= end) {

            if(s[start] != s[end]) {

                bool case1 = checkPalindrome(s, start+1, end);
                bool case2 = checkPalindrome(s, start, end-1);

                return case1 or case2;
            }

            start++;
            end--;
        }

        return true;
    }
};
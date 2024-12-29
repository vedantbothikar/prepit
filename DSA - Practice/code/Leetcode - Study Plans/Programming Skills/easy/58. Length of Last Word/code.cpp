/*

- https://leetcode.com/problems/length-of-last-word/?envType=study-plan-v2&envId=programming-skills





*/


class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int n = s.size();
        bool wordStart = false;
        int wordSize = 0;

        for(int i = n-1; i >= 0; i--) {

            while(s[i] == ' ') {
                if(wordStart) return wordSize;
                i--;
            }

            if (i >= 0 && s[i] != ' ') {
                wordStart = true;
                wordSize++;
            }
        }

        return wordSize;
    }
};
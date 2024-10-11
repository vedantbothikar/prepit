/*

- https://leetcode.com/problems/longest-repeating-character-replacement/description/
- https://gist.github.com/vedantbothikar/13bcc529390aa7a4d20744013959bf66
*/

class Solution {
public:
    int characterReplacement(string s, int k) {

        int maxLen = 0, n = s.size();

        for(char c = 'A'; c <= 'Z'; c++) {

            int replaced = 0, currLen = 0;
            int left = 0;
            for(int right = 0; right < n; right++) {

                if(s[right] == c) {
                    maxLen = max(maxLen, right - left + 1);
                }
                else {  // s[i] != c

                    if(replaced+1 <= k) {   // replaced+1 should be less than k because now we will be incrementing replaced and replaced should never be more than k
                        replaced++;
                    }
                    else {  // replaced is already equal to k, so we can't take any new replacements, shift window: left ptr shift until one replacement is REMOVED. so One ahead of a non c chactacer
                        
                        // make space for the new element in the window
                        while(left <= right && replaced == k) {

                            if(s[left] != c) {
                                replaced--;
                            }

                            left++;
                        }

                        replaced++; // add the new element to the window
                    }
                }

                maxLen = max(maxLen, right - left + 1);
            }

        }
        

        return maxLen;
    }
};
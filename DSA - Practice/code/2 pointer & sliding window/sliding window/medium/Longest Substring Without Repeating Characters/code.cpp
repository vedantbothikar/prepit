/*

- problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
- solution:
    - https://leetcode.com/problems/longest-substring-without-repeating-characters/solutions/3649636/3-method-s-c-java-python-beginner-friendly/
    - https://www.youtube.com/watch?v=wiGpQwVHdE0&ab_channel=NeetCode

unordered map
store the character and its index

if the character is unique:
    add the char to the map
    increment the right pointer
else: (not unique)
    update left pointer to index in map + 1
    update the new index of this char in map to right

HOW TO CHECK IF UNIQUE:
    - check if the character is present in the map
    OR
    - the the index of the character in the map is LESS than left


*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();
        int maxLen = INT_MIN;
        unordered_map<char, int> mp;

        // base case
        if(n == 0) return 0;

        int left = 0;

        for(int right = 0; right < n; right++) {

            char curr = s[right];
            // if unique character
            if(mp.find(curr) == mp.end() or mp[curr] < left) {
                mp[curr] = right;   // add in map
            }
            else {  // not unique
                left = mp[curr] + 1;
                mp[curr] = right;
            }

            int currLen = right - left + 1;
            maxLen = max(maxLen, currLen);
        }
        
        return maxLen;
    }
};
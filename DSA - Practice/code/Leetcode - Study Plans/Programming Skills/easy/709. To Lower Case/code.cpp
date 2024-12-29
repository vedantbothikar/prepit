/*

- https://leetcode.com/problems/to-lower-case/?envType=study-plan-v2&envId=programming-skills
- Problem: Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.


Remember to read this:
- https://gist.github.com/vedantbothikar/9ed94514e8e66c2567675239d20f2039
This explains how string in built function works in C++.

*/


class Solution {
public:
    string toLowerCase(string s) {
        
        string ans = "";
        for(char ch : s) {
            ans += tolower(ch);
        }

        return ans;
    }
};
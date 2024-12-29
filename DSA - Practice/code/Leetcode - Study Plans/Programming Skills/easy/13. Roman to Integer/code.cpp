/*

- https://leetcode.com/problems/roman-to-integer/?envType=study-plan-v2&envId=programming-skills

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000


Traverse every character
If we get I:
    - check if next element is 
        - I while loop until next element is I
        - V return 4
        - X return 9
If we get V:
    - just add it to ans
If we get X:
    - check if next element is
        - L return 40
        - C return 90
If we get L:
    - just add it to ans
If we get C:
    - check if next element is
        - D return 400
        - M return 900
If we get D:
    - just add it to ans
If we get M:
    - just add it to ans

*/
class Solution {

    void callI(string& s, int& i, int& ans) {

        int n = s.size();

        if(i+1 < n && s[i+1] == 'V') {
            ans += 4;
            i++;
            return;
        }
        
        if(i+1 < n && s[i+1] == 'X') {
            ans += 9;
            i++;
            return;
        }

        // curr character is last character
        if(i+1 == n) {
            ans += 1;
            return;
        }

        // CASE: next character will be I again
        ans += 1;
        i++;
        while(i < n) {

            if(s[i] == 'I') ans++;
            else return;

            i++;
        }
    }

    void callX(string& s, int& i, int& ans) {

        int n = s.size();

        if(i+1 < n && s[i+1] == 'L') {
            ans += 40;
            i++;
            return;
        }
        
        if(i+1 < n && s[i+1] == 'C') {
            ans += 90;
            i++;
            return;
        }

        ans += 10;
    }

    void callC(string& s, int& i, int& ans) {

        int n = s.size();

        if(i+1 < n && s[i+1] == 'D') {
            ans += 400;
            i++;
            return;
        }
        
        if(i+1 < n && s[i+1] == 'M') {
            ans += 900;
            i++;
            return;
        }

        ans += 100;
    }

public:
    int romanToInt(string s) {
        
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            
            if(s[i] == 'I') callI(s, i, ans);
            else if(s[i] == 'V') ans += 5;
            else if(s[i] == 'X') callX(s, i, ans);
            else if(s[i] == 'L') ans += 50;
            else if(s[i] == 'C') callC(s, i, ans);
            else if(s[i] == 'D') ans += 500;
            else if(s[i] == 'M') ans += 1000;
        }

        return ans;
    }
};
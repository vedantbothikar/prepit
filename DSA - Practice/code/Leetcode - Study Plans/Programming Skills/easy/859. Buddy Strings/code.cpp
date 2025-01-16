/*

- https://leetcode.com/problems/buddy-strings/?envType=study-plan-v2&envId=programming-skills

base condition:
- check lens of both strings

Logic:
Now traverse character by character
if the char does NOT match, then note down the index, 
also keep a countMisMatches
if ever the countMisMatches >= 3 return false

if misMatch:
    if ind1 != -1:
        ind1 = i
    else if ind2 != -1:
        ind2 = i
    else
        return false
else continue


*/
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        int ind1 = -1;
        int ind2 = -1;

        int n1 = s.size();
        int n2 = goal.size();

        vector<int> repeatingChars(26, 0);

        // base conditions
        if(n1 != n2) return false;

        for(int i = 0; i < n1; i++) {

            cout << "index: " << i << endl;
            repeatingChars[s[i] - 'a']++;

            if(s[i] == goal[i]) continue;

            // misMatch
            if(ind1 == -1) ind1 = i;
            else if(ind2 == -1) ind2 = i;
            else return false;
        }

        // all characters match
        if(ind1 == -1 && ind2 == -1) {
            
            // if the two string has repeating chars, then return true
            // else return false

            for(int i = 0; i < 26; i++) {
                if(repeatingChars[i] > 1) return true;
            }

            return false;
        }

        if(ind1 == -1 or ind2 == -1) return false;

        if(s[ind1] == goal[ind2] && s[ind2] == goal[ind1]) return true;
        return false;
    }
};
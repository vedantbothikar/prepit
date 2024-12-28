/*
- https://leetcode.com/problems/find-the-difference/?envType=study-plan-v2&envId=programming-skills



*/

class Solution {
public:
    char findTheDifference(string s, string t) {

        vector<int> mp(26, 0);

        // populate the map with the char counts of s
        for(char ch : s) {
            mp[ch - 'a']++;
        }

        for(int num : mp) {
            cout << "num: " << num << endl;
        }

        // reduce the count when traversing t
        for(char ch : t) {
            mp[ch - 'a']--;
        }

        for(int i = 0; i < 26; i++) {

            if(mp[i] < 0) {
                return (char)(i + 'a');
            }
        }

        return 'a';
    }
};
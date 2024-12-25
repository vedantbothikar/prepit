/*

- https://leetcode.com/problems/letter-combinations-of-a-phone-number/

*/

class Solution {

    void populateMap(unordered_map <char, string>& mp) {

        mp['2'] = "abc"; mp['3'] = "def"; mp['4'] = "ghi";
        mp['5'] = "jkl"; mp['6'] = "mno"; mp['7'] = "pqrs";
        mp['8'] = "tuv"; mp['9'] = "wxyz";
    }

    void solve(string& digits, unordered_map<char, string>& mp, int index, string& subans, vector<string>& ans) {

        // base condition
        if(index >= digits.size()) {
            ans.push_back(subans);
        }

        // Try all characters mapped to the current digit
        for (char ch : mp[digits[index]]) {
            subans.push_back(ch);           // Add current character
            solve(digits, mp, index + 1, subans, ans); // Recursive call
            subans.pop_back();              // Backtrack
        }
    }

public:
    vector<string> letterCombinations(string digits) {

        // base case when digits size is 0
        if(digits.size() == 0) return {};

        unordered_map <char, string> mp;
        populateMap(mp);
        
        vector<string> ans;
        string subans = "";
        
        int index = 0;

        solve(digits, mp, index, subans, ans);
        return ans;
    }
};
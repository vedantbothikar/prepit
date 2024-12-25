/*

- https://leetcode.com/problems/palindrome-partitioning/
- https://neetcode.io/solutions/palindrome-partitioning

we have to do combinations. We have to consider all substrings
and if any substring is palindrome:
    - Option 1: then we need to take this as a partition and then find rest partitions

    - Option 2: consider this character and keep adding more characters to the current partition


part: stores the partitions in current iteration
ans: stores the ans (list of all partitions)

TC: O(n * 2 ^n)
SC: O(n)

*/
class Solution {

    bool isPalindrome(string& s, int left, int right) {

        while(left <= right) {

            if(s[left] != s[right]) return false;

            left++;
            right--;
        }

        return true;
    }

    void solve(int left, string& s, vector<string>& part, vector<vector<string>>& ans) {

        // base condition
        if(left >= s.size()) {
            ans.push_back(part);
            return;
        }

        // try all partitions
        for(int right = left; right < s.size(); right++) {

            if(isPalindrome(s, left, right)) {

                part.push_back(s.substr(left, right-left+1));
                solve(right+1, s, part, ans);
                part.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> part;

        solve(0, s, part, ans);
        return ans;
    }
};
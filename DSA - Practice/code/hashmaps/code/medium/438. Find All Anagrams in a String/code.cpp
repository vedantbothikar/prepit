/*

Find All Anagrams in a String
Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/


*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int ns = s.size();
        int np = p.size();

        // base case
        if(np > ns) return {};

        // we will keep a window of fixed size and move it along s
        // whenever we find matches, we store the index

        vector<int> sCount(26, 0);
        vector<int> pCount(26, 0);

        // store the pCount as reference
        for(auto &ch : p) {
            pCount[ch - 'a']++;
        }

        // store the first possible anagram if it is correct in s
        for(int i = 0; i < np; i++) {
            sCount[s[i] - 'a']++;
        }

        vector<int> ans;
        // check if the sCount and pCount are equal
        if(sCount == pCount) ans.push_back(0);

        // check ahead in the array with the fixed window length
        int left = 0;
        for(int right = np; right < ns; right++) {

            // add the right element
            sCount[s[right] - 'a']++;

            // remove the left element
            sCount[s[left] - 'a']--;
            left++;

            // check if the sCount and pCount are equal
            if(sCount == pCount) ans.push_back(left);
        }

        return ans;
    }
};
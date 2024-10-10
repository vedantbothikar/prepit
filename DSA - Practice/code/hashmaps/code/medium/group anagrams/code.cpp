/*

- https://leetcode.com/problems/group-anagrams/
- explanation: https://gist.github.com/vedantbothikar/f83c5366855c49d64d7899dff36b1c7c

    group anagrams together

take one word at a time
hashmap<sortedString, vectorOfIndices>

NOTE: logic of sorting is that all anagrams will have the same sorted word at the end

loop through all words in the input: i

    sort word
    hashmap[word].push_back(i)

AT END:
Loop through the elements of the hashmap:
    loop thorugh the elements in the current key's vector:
        add these strings in a current vector
    add current vector to the ans vector

*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<int>> mp;

        // populate all sorted words in the hashmap along with their indices
        for(int i=0; i < strs.size(); i++) {

            string str = strs[i];
            string sortedStr = str; // we take a copy of the og string and then reverse because reversing str will also change the original string
            sort(sortedStr.begin(), sortedStr.end());
            mp[sortedStr].push_back(i);
        }

        vector<vector<string>> ans;
        // loop through hashmap and for each word populate ans for each word

        for(auto& [key, value] : mp) {

            vector<string> currentAns;
            // loop through all elements of indexArr
            for(int i : value) {
                currentAns.push_back(strs[i]);
            }

            ans.push_back(currentAns);
        }

        return ans;
    }
};
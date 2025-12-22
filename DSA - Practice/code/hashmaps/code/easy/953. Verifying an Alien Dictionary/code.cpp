/*

https://leetcode.com/problems/verifying-an-alien-dictionary/description/


Put every character of the order in a hashtable 
Example:
a : 0
b : 1
...


Now, Compare every adjacent words pair
If the order of ch in any of w1 is > w2: return false


*/
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {

        // populate hashtable with ch and orderNo.
        unordered_map<char, int> mp;
        int i = 0;
        for(char ch: order) {
            mp[ch] = i;
            i++;
        }

        // for every word, now check every next letter satisfies the condition
        // NOTE: we traverse till second last word
        int n = words.size();
        for(int i = 0; i < n-1; i++) {

            string w1 = words[i];
            string w2 = words[i+1];

            // now compare the order of each ch in w1 and w2
            for(int j = 0; j < w1.size(); j++) {

                // if we reach w2.size
                // Eg: "apple" and "app"
                if(j == w2.size()) return false;

                // check only when we get the first non-matching char
                if(w1[j] != w2[j]) {

                    // check the order of both chars
                    char ch1 = w1[j]; char ch2 = w2[j];

                    // if order of ch1 is greater: return false
                    if(mp[ch1] > mp[ch2]) {
                        return false;
                    }

                    // else: that means w1 is lexicographically smaller
                    // so we can break and try next words directly
                    break;
                }
            }
        }

        return true;        
    }
};
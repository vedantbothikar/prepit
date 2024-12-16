/*

- https://leetcode.com/problems/permutation-in-string/


sliding window
Take a window of size s1

Traaverse using the window in s2
For the current window check what elements do we have:
- do this by using a map of characters
- if the total characters in current window matches the total characters in s1
then we got a match

if not:
- slide the window

Complexity:

Time Complexity: O((n-m)*m + m)
Can be considered as O(n*m)


Space Complexity: O(1)
For explanation on complexity read this:
-https://gist.github.com/vedantbothikar/a30c30c4eb42895f4be0c026789636c4


*/
class Solution {

    bool isValidPermutation (vector<int>& mp1, vector<int>& mp2) {

        for(int i = 0; i < mp1.size(); i++) {
            
            if (mp1[i] != mp2[i]) return false;
        }

        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {

        int n1 = s1.size();
        int n2 = s2.size();

        if(n1 > n2) return false;

        vector<int> mp1(26, 0); // to store all chars of s1
        vector<int> mp2(26, 0); // to store chars in curr window

        // populate curr character count of s1 in mp1
        for(char ch : s1) {
            int currCh = ch - 'a';
            mp1[currCh]++;
        }

        int left = 0;
        int right = 0;

        while(right < n2) {

            // add right char to window
            int currCh = s2[right] - 'a';
            mp2[currCh]++;

            // slide window if not valid
            while(left <= right && (right-left+1 > n1)) {
                
                // remove the left character
                int currCh = s2[left] - 'a';
                mp2[currCh]--;

                left++;
            }

            // check if current window is valid permutation
            if((right-left+1 == n1) && isValidPermutation(mp1, mp2)) {
                return true;
            }

            right++;
        }

        return false;
    }
};
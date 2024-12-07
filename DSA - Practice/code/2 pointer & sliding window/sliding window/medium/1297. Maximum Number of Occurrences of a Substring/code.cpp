/*

You have to understand that the maxoccurrences will only occur of a substring whose length is minimum. If you consider the substr abc, then if you take abca or abcd
That will still have abc

So you will have to understand that the substr will max occurrences will ALWAYS be the one with smallest size

So, you should only search for minSize window

TC: O(n)


Optimization: Instead of the `winCharCnt`, you can also use a vector of length 26 since there are 26 characters only

*/
class Solution {

    bool isValidSubstr(int maxLetters, int uniqCnt, int minSize, int left, int right) {

        if(uniqCnt <= maxLetters && (right-left+1) == minSize) {
            return true;
        }

        return false;
    }

public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        
        int n = s.size();
        int left = 0;
        
        unordered_map <char, int> winCharCnt;
        int uniqCnt = 0; 

        unordered_map <string, int> occurrences;
        int maxOcc = 0;

        for(int right = 0; right < n; right++) {

            char rightChar = s[right];

            // Add right char to window
            if(winCharCnt[rightChar] == 0) uniqCnt++;
            winCharCnt[rightChar]++;

            // slide window if not correct
            if(right-left+1 > minSize) {

                // shift left ahead

                // if left char was unique
                char leftChar = s[left];
                if (winCharCnt[leftChar] == 1) uniqCnt--;
                winCharCnt[leftChar]--;
                
                left++;
            }

            if(isValidSubstr(maxLetters, uniqCnt, minSize, left, right)) {
                  
                string sub = s.substr(left, right-left+1);
                occurrences[sub]++;

                maxOcc = max(maxOcc, occurrences[sub]);
            }

        }

        return maxOcc;
    }
};
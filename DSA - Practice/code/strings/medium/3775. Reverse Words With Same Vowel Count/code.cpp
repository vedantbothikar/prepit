/*

3775. Reverse Words With Same Vowel Count

Problem Link:
https://leetcode.com/problems/reverse-words-with-same-vowel-count/


Edge cases:
- single word


Keep the vowels in an unordered_set
    - can check in O(1)


Traverse the string
For first word:
    - when you get a space, stop
    - during this keep a count of vowels 

Subsequent words:
    - when you get a space, stop
    - during this keep a count of vowels 
    - if vowelCnt == firstCnt:
        - reverse the word
            - Approach1:
                - maintain the start and end pointers of this word
                - then reverse using these pointers
                - in this approach you modify the original string itself
            - Approach2: (Memory Limit Exceeded)
                - as you traverse the word, store it (extra memory)
                - then reverse the entire string 
                - append this new string to first word with a space before
                - return the final string
            
Time: O(N)


*/
class Solution {

    void reverseWord(string &s, int startIdx, int endIdx) {

        while(startIdx < endIdx) {

            swap(s[startIdx], s[endIdx]);
            
            startIdx++;
            endIdx--;
        }
    }

public:
    string reverseWords(string input) {

        string s = input;

        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        // Calculate the count of vowels in first word
        int firstCnt = 0;   // first word's vowel cnt
        int index = 0;
        bool oneWordStr = false;
        for(char ch : s) {

            index++;
            
            if(ch == ' ') {
                oneWordStr = true;
                break;
            }

            // if ch is a vowel, increment the count
            if(vowels.find(ch) != vowels.end()) {
                firstCnt++;
            }
        }

        // EDGE CASE: if it is a string having only one single word: return as it is
        if(!oneWordStr) return s;


        // handle the last word
        s += ' ';


        // Process subsequent words
        int vowelCnt = 0;
        int startIdx = index;
        for(int i = index; i < s.size(); i++) {

            // if reached space
            if(s[i] == ' ') {

                // if vowelCnt matches: reverse the currWord
                if(vowelCnt == firstCnt) {
                    reverseWord(s, startIdx, i-1);
                }

                // reset
                vowelCnt = 0;
                startIdx = i + 1; // +1 since index is at space right now

                continue;
            }


            // if curr char is a vowel, increment the count
            if(vowels.find(s[i]) != vowels.end()) {
                vowelCnt++;
            }
        }

        // remove the last space character we added before
        s.pop_back();

        return s;
    }
};
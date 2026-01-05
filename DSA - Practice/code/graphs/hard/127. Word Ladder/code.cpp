/*

- Problem Link: https://leetcode.com/problems/word-ladder/

- Neetcode Solution: https://www.youtube.com/watch?v=h9iTnkgv05E&t=672s
(This is not exactly as what I have coded below, but it is a similar concept)


this is like a graph problem.

BFS
For every word:
    We have to find patterns of each word
        - this means change a single character at every position of every word
        - if this mutation is present in the given wordList, then traverse that


TC: O(N * L * 26)
SC: O(N)


*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        // convert the given wordList into a set
        unordered_set<string> wordListSet(wordList.begin(), wordList.end());

        // base case: check if endWord exists: if not: return 0
        if(!wordListSet.count(endWord)) return 0;

        // BFS

        queue<pair<int, string>> q;     // {dist, word}
        q.push({1, beginWord});
        wordListSet.erase(beginWord);   // NOTE: if beginWord exists, removed. If not, still works.

        while(!q.empty()) {

            auto [dist, currWord] = q.front();
            q.pop();

            // check if reached endWord
            if(currWord == endWord) return dist;

            // traverse neigbors
            // for every letter position in the word, make mutations
            for(int i = 0; i < currWord.size(); i++) {

                // try all 26 letters
                for(char ch = 'a'; ch <= 'z'; ch++) {

                    // mutate the character
                    string mutatedWord = currWord;
                    mutatedWord[i] = ch;

                    // if mutatedWord is not present in our wordList: ignore, do nothing
                    if(!wordListSet.count(mutatedWord)) continue;

                    // if mutatedWord is present in wordList, add to queue
                    // also remove from wordList now -> to mark as visited 
                    // and avoid infinite loop
                    q.push({dist+1, mutatedWord});
                    wordListSet.erase(mutatedWord);
                }
            }
        }

        return 0;
    }
};
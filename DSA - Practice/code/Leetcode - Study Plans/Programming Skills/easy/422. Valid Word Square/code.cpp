/*

- https://leetcode.com/problems/valid-word-square/?envType=study-plan-v2&envId=programming-skills

*/

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int cols = 0;
        int rows = words.size();
        vector<string> newWords;
        
        for (auto& word : words) {
            cols = max(cols, (int)word.size());
        }

        for (int col = 0; col < cols; ++col) {
            string newWord;

            // Iterate on each character of column 'col'.
            for (int row = 0; row < rows; ++row) {
                if (col < words[row].size()) {
                    newWord += words[row][col];
                }
            }
            // Push the new word of column 'col' in the list.
            newWords.push_back(newWord);
        }

        // Check if all row's words match with the respective column's words.
        return words == newWords;
    }
};
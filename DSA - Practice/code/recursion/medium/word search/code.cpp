/*

- https://leetcode.com/problems/word-search/description/
- https://youtu.be/pfiQ_PS1g8E?si=ep2Y-jxBvyr8unRY

- Time Complexity: O(n * m * 4^L), where n is the number of rows, m is the number of columns, and L is the length of the word. This is because in the worst case, every cell will explore 4 possible directions recursively.
- Space Complexity: O(n * m), for the visited array.

options:
- go left, right, up, down

where to start from?
you will always have to start from the first character of the word
so loop through all elements of the board and whenever you find the word[0], then start the recursion from there

we will need something to check if we have visited the element
- maintain a set of pair {row, col}

// base case
In following cases we have to stop traversing:
    - when row < 0, 
    - col < 0, 
    - row >= m, 
    - col >= n
    - when board[row][col] != string[i]   // current character in board is NOT equal to the character that we are looking for
    - when set contains {row, col}    // (means we have visited the position) 
    - when we got our word -> when currentWord == word

*/


class Solution {

    bool solve(vector<vector<char>>& board, string word, int row, int col, int index, vector<vector<bool>>& visited, int n, int m) {

        // base case
        if(index == word.size()) {
            return true;
        }

        if(row < 0 || col < 0 || 
            row >= n || col >= m || 
            board[row][col] != word[index] ||
            visited[row][col] == true   // means we have visited this row, col
          ) {

            return false;
        }

        // if we have reached here it means the character in board is equal to word[index]
        // choose this row, col 
        visited[row][col] = true;

        // try all 4 paths from current position
        bool ans = 
            solve(board, word, row+1, col, index+1, visited, n, m) ||
            solve(board, word, row-1, col, index+1, visited, n, m) ||
            solve(board, word, row, col+1, index+1, visited, n, m) ||
            solve(board, word, row, col-1, index+1, visited, n, m);

        // remove the added row,col from the map
        visited[row][col] = false;
        return ans;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(solve(board, word, i, j, 0, visited, n, m)) return true;
            }
        }

        return false;
    }
};
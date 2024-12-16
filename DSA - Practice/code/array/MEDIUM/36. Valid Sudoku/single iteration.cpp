class Solution {

    bool isPresentInSet(unordered_set<char>& s, char ele) {

        if(s.find(ele) != s.end()) return true;

        return false;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        // initialize a grid of unordered sets (grid size: 3 x 3)
        // to check duplicates in each square
        vector<vector<unordered_set<char>>> sqdups(3, vector<unordered_set<char>>(3));

        for(int i = 0; i < n; i++) {

            unordered_set <char> rowdups;    // to check duplicates in current row
            unordered_set <char> coldups;

            for(int j = 0; j < m; j++) {
                
                char currRowEle = board[i][j];
                char currColEle = board[j][i];
                char currSqEle = board[i][j];

                // Check row duplicate
                if(currRowEle != '.' && isPresentInSet(rowdups, currRowEle)) {
                    return false;
                }
                else if(currRowEle != '.') {
                    rowdups.insert(currRowEle);
                }

                // Check col duplicate
                if(currColEle != '.' && isPresentInSet(coldups, currColEle)) {
                    return false;
                }
                else if(currColEle != '.') {
                    coldups.insert(currColEle);
                }

                // Check for duplicate in square
                int srow = (i/3), scol = (j/3);
                if(currSqEle != '.' && isPresentInSet(sqdups[srow][scol], currSqEle)) {
                    return false;
                }
                else if (currSqEle != '.') {
                    sqdups[srow][scol].insert(currSqEle);
                }
            }
        }

        return true;
    }
};
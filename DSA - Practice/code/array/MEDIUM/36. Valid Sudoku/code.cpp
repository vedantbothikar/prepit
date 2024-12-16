/*

Essentially we just need to check for duplicates in:
- row
- col
- small grid

// TODO:
- can you optimize the set with a fixed size array

How to check for duplicates in a row?
- maintain a set, 
    if you find any duplicates, return false

Do the same for the columns

**Checking for small squares

We will maintain a single set for each small square
We will have 9 sets
From a row,col position we will need to identify which set to use

We will use the formula:
(row/3), (col/3)

our grid of sets:
vector<vector<unordered_set<int>>> s(3, vector<unordered_set>(3))
This will make a grid of 3,3 and each position will have a set

Time complexity: O(N 
2
 ) because we need to traverse every position in the board, and each of the four check steps is an O(1) operation.

Space complexity: O(N 
2
 ) because in the worst-case scenario, if the board is full, we need a hash set each with size N to store all seen numbers for each of the N rows, N columns, and N boxes, respectively.

*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        // check for duplicates in each row
        for(int i = 0; i < n; i++) {

            unordered_set <char> rowdups;    // to check duplicates in current row
            
            for(int j = 0; j < m; j++) {
                
                char currEle = board[i][j];
                if(currEle == '.') continue;
                // duplicate found
                if(rowdups.find(currEle) != rowdups.end()) {
                    cout << "dup in row" << " row,col: " << i << ", " << j << endl;
                    return false;
                }
                rowdups.insert(currEle);
            }
        }

        // check for duplicates in each col
        for(int i = 0; i < n; i++) {

            unordered_set <char> coldups;    // to check duplicates in current row
            for(int j = 0; j < m; j++) {
                
                char currEle = board[j][i];
                if(currEle == '.') continue;
                // duplicate found
                if(coldups.find(currEle) != coldups.end()) {
                    cout << "dup in col" << endl;
                    return false;
                }
                coldups.insert(currEle);
            }
        }

        // check for each square
        // initialize a grid of unordered sets (grid size: 3 x 3)
        vector<vector<unordered_set<char>>> sqdups(3, vector<unordered_set<char>>(3));

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                char currEle = board[i][j];
                if(currEle == '.') continue;
                
                int srow = (i/3), scol = (j/3);
                if(sqdups[srow][scol].find(currEle) != sqdups[srow][scol].end()) {
                    cout << "dup in square" << endl;
                    return false;
                }
                sqdups[srow][scol].insert(currEle);
            }
        }

        return true;
    }
};
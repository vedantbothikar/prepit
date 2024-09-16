/*

logic:
start from the border, apply dfs on all border nodes
from border nodes whichever 0s are connected all will be safe
The 0 nodes whichever are connected to the 0s at the border will be marked as #

at the end, whichever nodes were not connected, they will be marked as X 

Approach
To solve this problem correctly, you should:
Start DFS from border 'O' cells and mark them (and connected 'O' cells) as safe.
After processing all border cells, flip all remaining 'O' cells to 'X'.

This solution:

Uses DFS to mark all 'O' cells connected to the border as safe (using '#').
After DFS, it flips all unmarked 'O' cells to 'X' and restores safe cells ('#') to 'O'.


*/

int deltaRow[] = {0, 1, 0, -1};
int deltaCol[] = {-1, 0, 1, 0};

class Solution {

    bool validPos(vector<vector<char>>& board, int row, int col) {

        int n = board.size();
        int m = board[0].size();

        if(row >= 0 and row < n and col >=0 and col < m) {

            return true;
        }

        return false;
    }

    void dfs(vector<vector<char>>& board, int row, int col) {

        if(!validPos(board, row, col) or board[row][col] != 'O') {
            return;
        }

        board[row][col] = '#';

        // apply dfs for neighboours
        for(int i = 0; i < 4; i++) {

            int neighRow = row + deltaRow[i];
            int neighCol = col + deltaCol[i];
            dfs(board, neighRow, neighCol);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();

        // traversing borders with changing row and constant col
        for(int i = 0; i < n; i++) {
            dfs(board, i, 0);
            dfs(board, i, m-1);
        }
        
        // traversing borders with constant row and changing col
        for(int j = 0; j < m; j++) {
            dfs(board, 0, j);
            dfs(board, n-1, j);
        }

        // for every position where there is #, make it 0 and rest all as X
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
/*

- https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/description/?envType=study-plan-v2&envId=programming-skills

check if someone is a winner:
i can do a check in constant time

if even move: X plays
else: O plays


for(moves):
    if(evenMove) {
        matX[move[0]][move[1]] = 1;
        checkWinner(matX)
    }
    else {
        matO[move[0]][move[1]] = 1;
        checkWinner(matO)
    }


## Complexity:
Let n be the length of the board and m be the length of input moves.

Time complexity: O(m⋅n)

For every move, we need to traverse the same row, column, diagonal, and anti-diagonal, which takes O(n) time.

Space complexity: O(n 
2
 )

We use an n by n array to record every move.



*/
class Solution {

    void printMat(vector<vector<int>>& mat) {
        
        cout << "##########" << endl;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool checkWinner(vector<vector<int>>& mat) {

        // Check: row, col, diagonal
        
        for(int i = 0; i < 3; i++) {
            
            if(mat[i][0] && mat[i][1] && mat[i][2]) return true; // row
            if(mat[0][i] && mat[1][i] && mat[2][i]) return true; // col
        }

        // diagonal check
        if(mat[0][0] && mat[1][1] && mat[2][2]) return true; // left diagonal
        if(mat[0][2] && mat[1][1] && mat[2][0]) return true; // right diagonal

        return false;
    }

public:
    string tictactoe(vector<vector<int>>& moves) {
        
        int n = moves.size();

        vector<vector<int>> matX(3, vector<int>(3, 0));
        vector<vector<int>> matO(3, vector<int>(3, 0));

        for(int i = 0; i < n; i++) {

            vector<int> move = moves[i];

            if(i % 2 == 0) {    // even move
                matX[move[0]][move[1]] = 1;
                if(checkWinner(matX)) return "A";
            }
            else {
                matO[move[0]][move[1]] = 1;
                printMat(matO);
                if(checkWinner(matO)) return "B";
            }
        }   

        if(n == 9) return "Draw";

        return "Pending";
    }
};

/*
ALTERNATE SOLUTION:


*/

class Solution {
private:

    // Initialize the board, n = 3 in this problem.
    int n = 3;
    vector<vector<int>> board;

public:
    string tictactoe(vector<vector<int>>& moves) {        
        board.assign(n, vector<int>(n, 0));
        int player = 1;

        // For each move
        for (vector<int> move : moves) {
            int row = move[0];
            int col = move[1];

            // Mark the current move with the current playrer's id.
            board[row][col] = player;

            // If any of the winning conditions is met, return the current player's id.
            if (checkRow(row, player) || checkCol(col, player) || 
                (row == col && checkDiagonal(player)) ||
                (row + col == n - 1 && checkAntiDiagonal(player))) {
                return player == 1 ? "A" : "B";
                return player == 1 ? "A" : "B";
            }

            // If no one wins so far, change to the other player alternatively. 
            // That is from 1 to -1, from -1 to 1.
            player *= -1;
        }

        // If all moves are completed and there is still no result, we shall check if 
        // the grid is full or not. If so, the game ends with draw, otherwise pending.
        return moves.size() == 3 * 3 ? "Draw" : "Pending";
    }
    
    // Check if any of 4 winning conditions to see if the current player has won.
    bool checkRow(int row, int player) {
        for (int col = 0; col < n; ++col) {
            if (board[row][col] != player) return false;
        }
        return true;
    }
    
    bool checkCol(int col, int player) {
        for (int row = 0; row < n; ++row) {
            if (board[row][col] != player) return false;
        }
        return true;
    }
        
    bool checkDiagonal(int player) {
        for (int row = 0; row < n; ++row) {
            if (board[row][row] != player) return false;
        }
        return true;
    }
        
    bool checkAntiDiagonal(int player) {
        for (int row = 0; row < n; ++row) {
            if (board[row][n - 1 - row] != player) return false;
        }
        return true;
    }
};   
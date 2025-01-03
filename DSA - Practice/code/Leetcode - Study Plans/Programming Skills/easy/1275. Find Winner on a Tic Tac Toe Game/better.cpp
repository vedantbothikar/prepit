/*


Suppose we let the value of player A equal 1 and the value of player B equal -1. There are other ways to assign value, but 1 and -1 are the most convenient.

Therefore, a player will win if the value of any line equals n or -n. Thus after a move [row, col], we could calculate the value of row row and column col and check if the absolute value equals n. If this move is placed on the diagonal or the anti-diagonal, then we will check if the absolute value of the relative value equals n as well.

Thus, we just need to build two arrays to represent the values for each row and column. For instance, rows = [0, 0, 0], represents the initial value of row_1, row_2, and row_3, and the two values diag and anti_diag for value on diagonal and anti-diagonal.

To see how this will work, consider the two example moves shown below.

# COMPLEXITY:
Let n be the length of the board and m be the length of input moves.

Time complexity: O(m)

For every move, we update the value for a row, column, diagonal, and anti-diagonal. Each update takes constant time. We also check if any of these lines satisfies the winning condition which also takes constant time.

Space complexity: O(n)

We use two arrays of size n to record the value for each row and column, and two integers of constant space to record to value for diagonal and anti-diagonal.


*/


class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        
        // n stands for the size of the board, n = 3 for the current game.
        int n = 3;

        // Use rows and cols to record the value on each row and each column.
        // diag1 and diag2 to record value on diagonal or anti-diagonal.
        vector<int> rows(n), cols(n);
        int diag = 0;
        int anti_diag = 0;
        
        // Two players having value of 1 and -1, player_1 with value = 1 places first.
        int player = 1;
        
        for (vector<int> move : moves) {

            // Get the row number and column number for this move.
            int row = move[0];
            int col = move[1];
            
            // Update the row value and column value.
            rows[row] += player;
            cols[col] += player;
            
            // If this move is placed on diagonal or anti-diagonal, 
            // we shall update the relative value as well.
            if (row == col) {
                diag += player;
            }
            if (row + col == n - 1) {
                anti_diag += player;
            }
            
            // Check if this move meets any of the winning conditions.
            if (abs(rows[row]) == n || abs(cols[col]) == n || 
                abs(diag) == n || abs(anti_diag) == n) {
                return player == 1 ? "A" : "B";
            }
            
            // If no one wins so far, change to the other player alternatively. 
            // That is from 1 to -1, from -1 to 1.
            player *= -1;
        }
            
        // If all moves are completed and there is still no result, we shall check if
        // the grid is full or not. If so, the game ends with draw, otherwise pending.
        return moves.size() == n * n ? "Draw" : "Pending";
    }
};
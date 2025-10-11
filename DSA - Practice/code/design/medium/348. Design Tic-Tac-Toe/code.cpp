/*


    348. Design Tic-Tac-Toe
    Problem Statement: https://leetcode.com/problems/design-tic-tac-toe/
    Difficulty: Medium
    Topic: Design

*/

class TicTacToe {

    int n;
    vector<int> rows;
    vector<int> cols;
    int diag;
    int antidiag;

public:
    TicTacToe(int n) {

        rows.resize(n, 0);
        cols.resize(n, 0);

        diag = 0;
        antidiag = 0;   
        this->n = n;     
    }
    
    int move(int row, int col, int player) {
        
        int delta = (player == 1) ? 1 : -1;

        rows[row] += delta;
        cols[col] += delta;

        if(row == col) diag += delta;
        if(row + col == n-1) antidiag += delta;

        if(abs(rows[row]) == n or abs(cols[col]) == n or abs(diag) == n or abs(antidiag) == n) return player;

        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
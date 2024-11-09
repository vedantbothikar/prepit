/*

- https://leetcode.com/problems/number-of-islands/

This approach does not use any additional visited matrix

Approach
Traverse all elements, whenever you find a 1, apply dfs and mark all connected 1s as 0.

Complexity
Time complexity: O(n*m)
This is because we are traversing all elements once.

Space complexity: O(n*m)
This space is for Recursive call stack. This will occur in worst case when all of the elements are 1

*/

class Solution {

    void dfs(vector<vector<char>>& mat, int row, int col) {

        // base condition
        if(!(row >= 0 and row < mat.size() and col >= 0 and col < mat[0].size()) or (mat[row][col] == '0')) return;

        // change current value: since here value will be 1, change to 0 as something to mark as visited
        mat[row][col] = '0';

        // traverse in all 4 directions
        dfs(mat, row, col-1);
        dfs(mat, row, col+1);
        dfs(mat, row-1, col);
        dfs(mat, row+1, col);
    }

public:
    int numIslands(vector<vector<char>>& mat) {

        int n = mat.size(), m = mat[0].size();
        int count = 0;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(mat[i][j] == '1') {
                    count++;
                    dfs(mat, i, j);
                }

            }
        }
        
        return count;
    }
};
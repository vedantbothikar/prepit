/*

- https://leetcode.com/problems/max-area-of-island/

*/


/*

Approach:
- Visit every node in the grid, 
    - whenever you encounter '1'
        - apply dfs on this, wherever you have one, and keep a count
        - mark all visited nodes as 0

TC: O(n*m)
SC: O(n*m) // — Due to the recursion stack in the worst case.

*/
class Solution {

    // left, top, right, dowm
    vector<int> drow = {0, -1, 0, 1};
    vector<int> dcol = {-1, 0, 1, 0};

    void dfs(vector<vector<int>>& mat, int row, int col, int& currentCount) {

        // base condition
        if(!(row >= 0 and row < mat.size() and col >= 0 and col < mat[0].size())) return;

        if(mat[row][col] == 0) return;

        // mark as visited
        mat[row][col] = 0;
        currentCount++;

        // check in all 4 directions
        for(int i = 0; i < 4; i++) {
            dfs(mat, row + drow[i], col + dcol[i], currentCount);
        }
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& mat) {
        
        int maxCount = 0;
        
        int n = mat.size();
        int m = mat[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(mat[i][j] == 1) {

                    int currentCount = 0;
                    dfs(mat, i, j, currentCount);
                    
                    maxCount = max(maxCount, currentCount);
                }
            }
        }

        return maxCount;
    }
};
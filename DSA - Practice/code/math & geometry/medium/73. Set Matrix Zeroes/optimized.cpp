/*

- https://leetcode.com/problems/set-matrix-zeroes/description/
Watch video:
- https://www.youtube.com/watch?v=N0MgLvceX7M&ab_channel=takeUforward

col0 = 1
first row 
first col


OR ELSE check alternate_optimized.cpp

*/


class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        // marking wherever we get 0s
        int col0 = 1;
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j ++) {

                if(mat[i][j] == 0) {

                    // mark first col as 0
                    mat[i][0] = 0;

                    if(j != 0) mat[0][j] = 0;
                    else col0 = 0;
                }
            }
        }

        // wherever first row or col as 0, mark value as 0
        for(int i = 1; i < n; i++) {

            for(int j = 1; j < m; j ++) {

                if(mat[0][j] == 0 or mat[i][0] == 0) {
                    mat[i][j] = 0;
                }
            }
        }

        
        // handle first row
        if(mat[0][0] == 0) {
            for(int j = 0; j < m; j++) mat[0][j] = 0;
        }

        if(col0 == 0) {
            for(int i = 0; i < n; i++) mat[i][0] = 0;
        }
    }
};
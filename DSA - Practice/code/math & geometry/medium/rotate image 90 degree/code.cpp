/*


- problem: https://leetcode.com/problems/rotate-image/description/
- GOOD explanation: https://leetcode.com/problems/rotate-image/solutions/3440564/animation-understand-in-30-seconds/

Transpose then reverse the columns

*/


class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        
        int n = mat.size();

        // transpose
        for(int i = 0; i < n; i++) {

            for(int j = i+1; j < n; j++) {

                swap(mat[i][j], mat[j][i]);
            }
        }
        
        // swap columns (reverse each row)
        for(int row = 0; row < n; row++) {
            reverse(mat[row].begin(), mat[row].end());
        }   
    }
};
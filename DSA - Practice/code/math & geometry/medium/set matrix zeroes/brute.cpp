/*

- https://leetcode.com/problems/set-matrix-zeroes/description/
Watch video:
- https://www.youtube.com/watch?v=N0MgLvceX7M&ab_channel=takeUforward


We could use a hashset to store the row and col of wherever there are zeroes

then in next traversal, whenever the row or col is present in the set
call a function to make the row and col zero
and skip this row and col traversal

*/


class Solution {

    void makeZero(vector<vector<int>>& mat, int givenRow, int givenCol) {

        int n = mat.size();
        int m = mat[0].size();

        // all same row values
        for(int j = 0; j < m; j++) {
            mat[givenRow][j] = 0;
        }

        // all same col values
        for(int i = 0; i < n; i++) {
            mat[i][givenCol] = 0;
        }
    }

public:
    void setZeroes(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        unordered_map<int, unordered_set<int>> mp;
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(mat[i][j] == 0) {
                    mp[i].insert(j);
                }
            }
        }

        for(auto& [key, vecValue] : mp) {
            cout << key << " ";

            for(int i : vecValue) cout << i << " ";
        }

        // make zeroes
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(mp.count(i) > 0 and mp[i].count(j) > 0) {

                    makeZero(mat, i, j);
                }
            }
        }
    }
};
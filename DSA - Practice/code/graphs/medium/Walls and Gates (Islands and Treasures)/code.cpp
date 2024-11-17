/*

- https://neetcode.io/problems/islands-and-treasure
- https://leetcode.com/problems/walls-and-gates/
- Watch: https://youtu.be/e69C6xhiSQE


DFS solution:
This means from every island we will apply dfs and check if we are reaching treasure
This means we have to traverse full grid and for every island we
have to apply dfs

TC: O((m*n)^2)

BFS:
If we apply BFS from all the treasures (so thinking  backward)
If we do this, then we can do it in O(m*n)
- Watch: https://youtu.be/e69C6xhiSQE

Initially store all positions where the treasures are present in the queue
Now apply BFS on that queue
    - whenever you encounter INF, mark the distance
    - if anything else, just do nothing



*/
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        // queue to store the treasure positions initially
        queue<pair<int, int>> q;    // pair {row, col}
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(mat[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        vector<int> drow = {0, -1, 0, 1};
        vector<int> dcol = {-1, 0, 1, 0};

        // Apply BFS
        while(!q.empty()) {

            pair<int, int> p = q.front();
            int row = p.first;
            int col = p.second;
            q.pop();

            // Traverse in all 4 directions
            for(int i = 0; i < 4; i++) {
                
                // check if new row & col are valid
                int newRow = row + drow[i];
                int newCol = col + dcol[i];

                if(newRow < 0 or newRow >= n or newCol < 0 or newCol >= m) {
                    continue;
                }

                // if it is not a position that can be traversed: like 0 or -1 or some position changed with the steps
                if(mat[newRow][newCol] != INT_MAX) {
                    continue;
                }

                int distance = 1 + mat[row][col];   // 1 + oldDistance value
                mat[newRow][newCol] = distance;

                q.push({newRow, newCol});
            }

        }

    }
};














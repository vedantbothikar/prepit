/*

Problem Name: Shortest Bridge
Leetcode ID: 934
- Problem Link: https://leetcode.com/problems/shortest-bridge/



- first do a dfs on one of the islands, and then convert all of these values to 2
    - this will help us in distinguishing between the two islands

- now start a bfs from all of the 2s towards the 1s (multi source bfs kind of)
    - return the steps you required to reach your goal



*/
class Solution {

    void dfsToConvert(vector<vector<int>>& grid, int row, int col, queue<pair<int, pair<int, int>>>& q) {

        int n = grid.size();
        int m = grid[0].size();

        // base case: if row and col are not in bounds
        if(row < 0 or row >= n or col < 0 or col >= m) return;

        // make sure the current value is 1
        if(grid[row][col] != 1) return;

        // conver the value to 2 and then add to queue
        grid[row][col] = 2;
        q.push({0, {row, col}});

        // traverse the neigbhors
        vector<int> dr = {0, -1, 0, 1};
        vector<int> dc = {-1, 0, 1, 0};

        for(int i = 0; i < 4; i++) {

            int newR = row + dr[i];
            int newC = col + dc[i];          

            dfsToConvert(grid, newR, newC, q);
        }

        return;
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, pair<int, int>>> q; // {dist, {row, col}}

        // dfs to convert values of one of the islands to "2"
        bool found = false;
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {
                
                if(grid[i][j] == 1) {
                    dfsToConvert(grid, i, j, q);
                    found = true;
                    break;
                }
            }

            if(found) break;
        }

        // now start a bfs from all of the cells of the second island
        while(!q.empty()) {

            // pop the front
            auto [dist, p] = q.front();
            auto [row, col] = p;
            q.pop();

            // add neigbors to q
            vector<int> dr = {0, -1, 0, 1};
            vector<int> dc = {-1, 0, 1, 0};

            for(int i = 0; i < 4; i++) {

                int newR = row + dr[i];
                int newC = col + dc[i];

                // check if the newR, newC are in bounds and they are NOT 2
                if(newR < 0 or newR >= n or newC < 0 or newC >= m) continue;
                if(grid[newR][newC] == 2) continue;

                // check if we have reached the destination
                if(grid[newR][newC] == 1) {
                    return dist;
                }

                // we are on a "0": mark as visited (by changing to 2), and adding to queue
                // NOTE: if you dont mark as "2", there will be inifinite loop
                // reason: the same cell will be repeated (it is neighbor of multiple cells)
                grid[newR][newC] = 2;
                q.push({dist+1, {newR, newC}});
            }
        }

        return -1;  // will never reach here if valid inputs to the problem
    }
};
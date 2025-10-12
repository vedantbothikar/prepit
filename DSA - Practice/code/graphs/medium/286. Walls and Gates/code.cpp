/*

286. Walls and Gates
- Problem Link: https://leetcode.com/problems/walls-and-gates/description/
- Neetcode: https://neetcode.io/solutions/walls-and-gates


*/


class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {

        // multi source bfs
        // start from the gates

        int n = rooms.size();
        int m = rooms[0].size();

        // add all gates to the queue
        queue<pair<int, int>> q;    // {row, col}

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(rooms[i][j] == 0) q.push({i, j});
            }
        }

        // bfs from the gates
        
        vector<int> dr = {0, -1, 0, 1};
        vector<int> dc = {-1, 0, 1, 0};

        while(!q.empty()) {

            auto [row, col] = q.front();
            q.pop();

            // traverse in 4 directions
            for(int i = 0; i < 4; i++) {
                int newR = row + dr[i];
                int newC = col + dc[i];

                // check: bounds. Also check if the element is NOT INF
                if(newR < 0 or newR >= n or newC < 0 or newC >= m or rooms[newR][newC] != INT_MAX) continue;

                // mark the distance
                rooms[newR][newC] = rooms[row][col] + 1;
                q.push({newR, newC});
            }
        }
    }
};
/*

- https://leetcode.com/problems/shortest-distance-from-all-buildings

Time: O(N^2 * M^2) in worst case, where N = number of rows, M = number of columns
Space: O(N * M) for the visited array and the queue in BFS

*/

class Solution {

    int bfs(int startRow, int startCol, vector<vector<int>>& grid, int totBldgs) {

        int n = grid.size();
        int m = grid[0].size();

        int totalDistance = 0;
        int totalBldgsVisited = 0;

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>> q;    // {{row, col}, dist}

        // left, up, right, down
        vector<int> dr = {0, -1, 0, 1};
        vector<int> dc = {-1, 0, 1, 0};

        // insert the startNode
        q.push({{startRow, startCol}, 0});
        visited[startRow][startCol] = true;

        while(!q.empty()) {

            int row = q.front().first.first;
            int col = q.front().first.second;
            int currDist = q.front().second;

            q.pop();

            // check if we have reached a building
            if(grid[row][col] == 1) {
                totalDistance += currDist;
                totalBldgsVisited++;
                continue;
            }

            // check for neighbors
            for(int i = 0; i < 4; i++) {

                int newR = row + dr[i];
                int newC = col + dc[i];

                // check bounds
                if(!(newR >= 0 and newR < n and newC >= 0 and newC < m)) continue;

                // check if not visited and not obstacle
                if(!visited[newR][newC] and grid[newR][newC] != 2) {
                    visited[newR][newC] = true;
                    q.push({{newR, newC}, currDist+1});
                }
            }
        }

        if(totalBldgsVisited == totBldgs) return totalDistance;

        // but if we have not visited all of the buildings, that means it is not able to reach all buildings from this location.
        // but this also means that it is not possible to reach all of this buildings from any location in the bfs path of this
        // so simply mark all nodes as obstacles in the current visited bfs so that we 
        // dont apply bfs on this path once again later

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // mark as obstacle
                if(grid[i][j] == 0 and visited[i][j] == true) {
                    grid[i][j] = 2;
                }
            }
        }

        // since we couldn't reach all buildings
        return INT_MAX;
    }

public:
    int shortestDistance(vector<vector<int>>& grid) {
        
        int minDistance = INT_MAX;

        int rows = grid.size();
        int cols = grid[0].size();

        int totBldgs = 0;

        // count total buildings to reach (destNodes)
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1) totBldgs++;
            }
        }

        // apply BFS from all empty lands to the destNodes
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {

                if(grid[i][j] == 0) {

                    int currTotDistance = bfs(i, j, grid, totBldgs);
                    cout << currTotDistance << endl;
                    minDistance = min(minDistance, currTotDistance);
                }
            }
        }

        if(minDistance == INT_MAX) return -1;

        return minDistance;
    }
};
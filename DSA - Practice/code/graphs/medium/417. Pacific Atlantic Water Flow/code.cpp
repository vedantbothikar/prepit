/*
- https://leetcode.com/problems/pacific-atlantic-water-flow/description/

So as per the question, from a position if the adjacent location is smaller then the water can flow. But we will solve the question in reverse direction, let's start traversing from the oceans to inside.
So we will have to check if the adjacent positions have a height greater than the current height.

Approach:
- Traverse once from corners of pacific ocean and mark positions as true (wherever the level is higher than the current level)
- Do similar for atlantic ocean
- Now compare the positions wherever pacific and atlantic meeet

TC: O(m*n)
SC: O(m*n)

*/
class Solution {

    // left, top, right, down
    vector<int> drow = {0, -1, 0, 1};
    vector<int> dcol = {-1, 0, 1, 0};

    bool isValid(int row, int col, vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        if(row >= 0 and row < n and col >= 0 and col < m) return true;

        return false;
    }

    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<int>>& ocean) {

        // logic: mark as true (water can flow here)
        ocean[row][col] = true;


        // traverse in 4 directions
        for(int i = 0; i < 4; i++) {

            int newRow = row + drow[i];
            int newCol = col + dcol[i];

            if(!isValid(newRow, newCol, heights)) continue;

            // if already visited
            if(ocean[newRow][newCol] == true) continue;

            // traverse only if the height if greater than current
            if(heights[newRow][newCol] >= heights[row][col]) {
                
                // cal dfs on the new position
                dfs(newRow, newCol, heights, ocean);
            }
        }

    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pacific(n, vector<int>(m, false));
        vector<vector<int>> atlantic(n, vector<int>(m, false));

        // traverse the top and bottom rows
        for(int j = 0; j < m; j++) {
            
            dfs(0, j, heights, pacific);
            dfs(n-1, j, heights, atlantic);
        }

        // traverse the left and right cols
        for(int i = 0; i < n; i++) {

            dfs(i, 0, heights, pacific);
            dfs(i, m-1, heights, atlantic);
        }
        
        vector<vector<int>> ans;
        // compare the pacific and atlantic positions
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(pacific[i][j] && atlantic[i][j]) {

                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
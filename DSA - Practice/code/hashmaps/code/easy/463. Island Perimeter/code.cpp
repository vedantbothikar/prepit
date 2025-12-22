/*

https://leetcode.com/problems/island-perimeter/description/

463. Island Perimeter


Observation: for perimeter: 
- consider a cell of land
- in whichever direction there is another piece of land, that edge is not counted for the perimeter.
- this means we just have to calculate (4 - no.OfNeighboringLandCells) for perimeter of that particular cell
- keep adding this for all cells

Approach:
- dfs 
    - whenever we find land:
        - totPer += calculatePerimeterOfCell(currCell)

TC: O(n*m*4)
SC: O(1)


*/
class Solution {

    int calculatePeriForACell(int row, int col, vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // check all 4 directions if they are land
        vector<int> dr = {0, -1, 0, 1};
        vector<int> dc = {-1, 0, 1, 0};

        int perimeter = 4;
        for(int i = 0; i < 4; i++) {
            
            int newR = row + dr[i];
            int newC = col + dc[i];

            // check newR and newC are in bounds
            if(newR < 0 or newR >= n or newC < 0 or newC >= m) continue;

            // if land, decrement res by 1
            if(grid[newR][newC] == 1) perimeter -= 1;
        }

        cout << "row, col: " << row << ", " << col << "; perimeter: " << perimeter << endl;
        return perimeter;
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int totPerimeter = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1) {
                    totPerimeter += calculatePeriForACell(i, j, grid);
                }
            }
        }

        return totPerimeter;
    }
};
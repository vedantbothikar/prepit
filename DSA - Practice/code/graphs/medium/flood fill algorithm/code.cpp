/*

    initColor
    newColor

    - Perform dfs algo on the matrix
        - color whichever spots are equal to the initColor

*/



class Solution {

private:

    // the number by which we need to modify the row and col if we move left, up, right, or down
    int deltaRow[4] = {0, 1, 0, -1};
    int deltaCol[4] = {-1, 0, 1, 0};

    void dfs(vector<vector<int>>& image, int row, int col, int initColor, int newColor) {

        // color the current position
        image[row][col] = newColor;

        // traverse in rest 4 directions
        for(int i = 0; i < 4; i++) {

            int neighbourRow = row + deltaRow[i];
            int neighbourCol = col + deltaCol[i];

            // check if the new neighbour position is even valid or not
            if(neighbourRow >=0 and neighbourRow < image.size() and neighbourCol >= 0 and neighbourCol < image[0].size()) {

                // check if the existing color is equal to the initColor
                if(image[neighbourRow][neighbourCol] == initColor) {

                    // call dfs on the new positon
                    dfs(image, neighbourRow, neighbourCol, initColor, newColor);
                }
            }
        }
    }


public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int initColor = image[sr][sc];
        int newColor = color;

        if(initColor == newColor) return image;

        dfs(image, sr, sc, initColor, newColor);
        return image;
    }
};
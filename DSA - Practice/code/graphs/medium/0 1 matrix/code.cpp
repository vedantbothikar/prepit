/*

- problem: https://leetcode.com/problems/01-matrix/
- SOlution: https://www.youtube.com/watch?v=edXdVwkYHF8

BFS algorithm apply
We want to find the distance of nearest 0 for each cell.
So for every 1 we need to find thr distance of nearest 0
So for every 0 the distance of nearest 0 will be 0 itself


So, initially we will push all the zeroes in the matrix in the queue
queue will store
{{row, col}, distance}
so it will store the position (using row and col) and also the distance from nearest 0

Approach:
- first we will store the position and location of all 0s in the queue
- until queue is empty (applying BFS)
- for every element in the queue, find the neighbouring elements
- for every neighbour 
    - mark them as visited,
    - write the distance in the distance matrix
    - push this neighbour to the queue


*/

int deltaRow[] = {0, 1, 0, -1};
int deltaCol[] = {-1, 0, 1, 0};

class Solution {

    bool validPos(int row, int col, int n, int m) {

        if(row >= 0 and row < n and col >=0 and col < m) {

            return true;
        }

        return false;
    }

    vector<vector<int>> solveBfs(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        // make visited and distance grids of size nxm and initialize to 0
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> distance(n, vector<int>(m, 0));

        queue<pair<pair<int,int>, int>> q;

        // Push all elements which are equal to 0 in the matrix
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(mat[i][j] == 0) {
                    vis[i][j] = 1;
                    distance[i][j] = 0;
                    q.push({{i, j}, 0});  // pushing {{row, col}, dist}
                }
            }
        }


        // Apply BFS on queue
        while(!q.empty()) {

            pair<pair<int, int>, int> p = q.front();
            int row = p.first.first;
            int col = p.first.second;
            int currDist = p.second;
            q.pop();

            distance[row][col] = currDist;

            // find the 4 neighbours
            for(int i = 0; i < 4; i++) {

                int neighRow = row + deltaRow[i];
                int neighCol = col + deltaCol[i];

                if(validPos(neighRow, neighCol, n, m) && vis[neighRow][neighCol] == 0) {  // if not visited yet
                    vis[neighRow][neighCol] = 1;
                    q.push({{neighRow, neighCol}, currDist+1});   // increment distance
                }
            }
        }

        return distance;
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        return solveBfs(mat);
    }
};
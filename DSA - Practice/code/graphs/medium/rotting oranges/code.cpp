/*

    - Initially
        - count the number of fresh oranges we are given
        - Find the rotten and store them in a queue

    Queue structure:
    
    queue<pair<pair<int, int>, int> q;
    Example: {{row, col}, time}
        inner pair will contain the row and col and the second parameter of outer 
        pair will contain the time 

    - Now run BFS on every rotten orange
        - Why BFS only? Because we want to calculate the time taken, and at every 
        unit of time, multiple rotten oranges will do their work of rotting others,
        so at a particular level/time we want to rot multiple fresh ones.

    - During BFS, for every rotten out of the queue,
        - rot the neighbouring 4 elements as well
        - if they were fresh, now rot them and add them to the queue
        Also, whenever the child (or new fresh orange was rottened), increase the 
        time unit by 1 while adding the new rotten to the queue
    
    - In this same BFS, as we keep rotting the oranges, maintain a count of 
    how many organges you decayed. 
    
    - Finally after completing the BFS, check the count of oranges you decayed and 
    compare that with initial count of fresh oranges, if they match then return the
    time. Else return -1;


*/


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<pair<int, int>, int>> rottenq;
        int n = grid.size();
        int m = grid[0].size();
        int countFresh = 0;

        // populate the rotten oranges in the queue
        // calculate how many fresh oranges we have at the beginning
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 2) {
                    rottenq.push({{i,j}, 0});    // pushing the {{row, col}, time}
                }

                if(grid[i][j] == 1) {
                    countFresh++;
                }
            }
        }

        int countRotten = 0;
        int maxTime = 0;

        // run BFS on the graph
        while(!rottenq.empty()) {

            // now considering a rotten orange
            int row = rottenq.front().first.first;
            int col = rottenq.front().first.second;
            int time = rottenq.front().second;
            rottenq.pop();

            maxTime = max(maxTime, time);

            // now for this rotten orange, rot all neighbouring fresh oranges

            // delta to move left, up, right, down
            int deltaRow[] = {0, 1, 0, -1};
            int deltaCol[] = {-1, 0, 1, 0};

            // rot the neighbouring fresh oranges on all 4 neighbours
            for(int i = 0; i < 4; i++) {
                
                // finding the location of the neigbouring element
                int neighbourRow = row + deltaRow[i];
                int neighbourCol = col + deltaCol[i];

                // checking if the location is valid or not (since we are adding and reducing value from the row and col values, it could go below or above bounds)
                if(neighbourRow >= 0 and neighbourRow < n and neighbourCol >= 0 and neighbourCol < m) {

                    // check if the element on this location is a fresh orange
                    if(grid[neighbourRow][neighbourCol] == 1) {

                        // rot them now
                        grid[neighbourRow][neighbourCol] = 2;
                        countRotten++;

                        rottenq.push({{neighbourRow, neighbourCol}, time+1});
                    }
                }
            }
        }

        // check if all fresh oranges are now rotten or not
        if(countFresh == countRotten) {
            return maxTime;
        }

        return -1;    
    }
};
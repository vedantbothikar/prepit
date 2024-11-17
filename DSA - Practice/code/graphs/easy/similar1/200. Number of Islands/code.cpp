/*

SOLUTION: https://www.youtube.com/watch?v=ACzkVtewUYA
LEETCODE: https://leetcode.com/problems/number-of-provinces/


*/

class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& visited) {

        visited[node] = 1;

        for (int i = 0; i < isConnected[0].size(); i++) {

            if (isConnected[node][i] == 1 and !visited[i]) {
                
                dfs(i, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        vector<int> visited(isConnected[0].size(), 0);
        int count = 0;

        for (int i = 0; i < isConnected[0].size(); i++) {

            if (!visited[i]) {
                count++;
                dfs(i, isConnected, visited);
            }
        }

        return count;
    }
};
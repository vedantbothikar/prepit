/*

- https://leetcode.com/problems/redundant-connection/
- https://neetcode.io/solutions/redundant-connection

We will loop to create an adjancency list and for every iteration we will check if there is a loop detected. If we find a loop, then return the latest edge that caused the loop to occur.


Note: as there could be multiple possible edges that create the loop, but since we are traversing in the order of edges, we will always get the last occurring edge that causes problem because we are initially completing the rest of the edges required for a complete loop. think about it.


TC: O(E * (V+E))
(Since for every edge we are runnning a DFS to check for a loop)


SC: O(V+E)
// visited and adjacency list

*/
class Solution {

    bool loopDetected(int node, int parent, vector<vector<int>>& adj, vector<int>& visited) {

        // loop detected
        if(visited[node] == true) {
            return true;
        }

        // mark as visited
        visited[node] = true;

        // dfs on neighbours: except the parent
        for(int nei : adj[node]) {

            if(nei != parent) {

                // return true if loop detected when dfs on neighbours
                if(loopDetected(nei, node, adj, visited)) {
                    return true;
                }
            }
        }

        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        vector<vector<int>> adj(n+1);

        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            vector<int> visited(n+1, false);
            if(loopDetected(u, -1, adj, visited)) {
                return {u, v};
            }
        }

        // will never reach here since loop is guaranteed as per question
        return {};
    }
};
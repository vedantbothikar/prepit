/*

- https://neetcode.io/problems/count-connected-components
- https://neetcode.io/solutions/number-of-connected-components-in-an-undirected-graph


- Create adjancency list
- visit all elements (that are not marked as visited) (dfs)
    - as and when you visit a node, it will be a new component. count++

*/
class Solution {

    void dfs(int currNode, int parent, unordered_map<int, vector<int>>& mp, unordered_set<int>& visited) {

        // base condition: already visited
        if(visited.count(currNode)) return;

        // mark as visited
        visited.insert(currNode);

        // traverse neighbours
        for(int neighbour : mp[currNode]) {
            
            if(neighbour == parent) continue;

            if(!visited.count(neighbour)) {

                dfs(neighbour, currNode, mp, visited);
            }
        }

        return;
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> mp;

        // Step 1: Create adjancency list
        for(auto edge : edges) {

            int first = edge[0];
            int second = edge[1];

            mp[first].push_back(second);
            mp[second].push_back(first);
        }

        // Step 2: visit all nodes (dfs)
        unordered_set<int> visited;
        int count = 0;
        for(int i = 0; i < n; i++) {

            if(!visited.count(i)) {
                
                int currNode = i;
                int parent = -1;
                count++;

                dfs(currNode, parent, mp, visited);
            }
        }

        return count;
    }
};

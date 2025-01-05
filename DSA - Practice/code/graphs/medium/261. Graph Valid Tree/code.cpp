/*

- https://neetcode.io/problems/valid-tree
- https://leetcode.com/problems/graph-valid-tree/description/?envType=problem-list-v2&envId=anl1el4e

- https://neetcode.io/solutions/graph-valid-tree

Conditions for a valid tree:
Condition 1: No loop
Condition 2: No disconnected nodes

How to check Condition 1:
- Create adjacency list
- For every node, visit its neighbours, and when visiting if you find it again, then cycle detected
(will need a set: visited)


How to check Condition 2:
- If we have visited all nodes in checking condition 1, then we are good here.


TC: O(V+E)
SC: O(V+E)

*/
class Solution {

    // perform dfs
    bool loopDetected(int currNode, int parent, unordered_map<int, vector<int>>& mp, unordered_set<int>& visited) {

        // base condition: already visited
        if(visited.count(currNode)) {
            return true;
        }

        visited.insert(currNode);

        // visit all neighbours of currNode
        for(int neighbour : mp[currNode]) {

            if(neighbour == parent) continue;   // since it is undirected graph

            if(loopDetected(neighbour, currNode, mp, visited)) {
                return true;
            }
        }

        return false;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {

        unordered_set<int> visited;

        unordered_map<int, vector<int>> mp;
        // Step 1: create an adjacency list
        for(auto p : edges) {

            int first = p[0];
            int second = p[1];

            mp[first].push_back(second);
            mp[second].push_back(first);    // we need to add to both because it is an undirected graph
        }

        // Step 2: Detect cycle in undirected graph
        // we can start with any node, let's start with currNode as 0
        int currNode = 0;
        int parent = -1;
        if(loopDetected(currNode, parent, mp, visited)) {
            return false;
        }

        // Step 3: Check disconnected nodes. So, if we have visited n nodes already: return true
        if(visited.size() == n) {
            return true;
        }

        // if not visited all n nodes, that means there are some disconnected nodes: so not a valid tree. return false
        return false;
    }
};

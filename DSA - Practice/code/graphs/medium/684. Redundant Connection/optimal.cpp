/*

Optimal Approach:

Watch video at: https://neetcode.io/solutions/redundant-connection

For the optimal approach we will use the Union-Find Algorithm which has parent and rank lists.

What you have to do is that for every edge, you create a union of the two vertices. And while doing union, if you ever find that the parent of two vertices are the same, then that means there is a loop and you return the edge that is causing the problem


*/
class Solution {

    // here we will find the root parent of the node
    // Logic: until the parent of the node is the node, keep checking the parent
    // Note that the parent of the root node will always be the root node itself
    int findRootPar(int node, vector<int>& parent) {

        int rootPar = parent[node];

        while(rootPar != parent[rootPar]) {

            rootPar = parent[rootPar];
        }

        return rootPar;
    }

    bool Union(int u, int v, vector<int>& parent, vector<int>& rank) {

        // find the root parents of u and v
        int rpar1 = findRootPar(u, parent);
        int rpar2 = findRootPar(v, parent);

        // in case parents are the same, there is a loop 
        if(rpar1 == rpar2) {
            return false;
        }

        // if parents are not the same, create a union
        // whichever's rank is higher, they will get the other one as a child

        if(rank[rpar1] > rank[rpar2]) {
            
            // make the parent of v as u. And increment the rank of u with that of v
            parent[rpar2] = rpar1;
            rank[rpar1] += rank[rpar2];
        }
        else {
            
            // do the opposite of what you did in if condition
            parent[rpar1] = rpar2;
            rank[rpar2] += rank[rpar1];
        }

        return true;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector<int> parent(n+1);
        vector<int> rank(n+1, 1);   // initially all ranks will be 1

        // populate the parent for each vertex: initiall all parents are the nodes themselves
        // Note that the parent nodes initially will always be the root node itself
        for(int i = 1; i <= n; i++) {

            parent[i] = i;
        }

        // do the union for each edge
        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];
            
            if(!Union(u, v, parent, rank)) {
                return {u, v};
            }
        }

        // we will never reach here since qs says there will always be one such edge
        return {};
    }
};
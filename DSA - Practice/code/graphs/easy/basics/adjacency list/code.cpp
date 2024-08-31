    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        // Code here
        
        vector<vector<int>> ans(V+1);   // adjacency list
        
        // for each pair of edges
        for(pair<int,int> p : edges) {
            
            // store the relation in the adjacency list
            ans[p.first].push_back(p.second);
            ans[p.second].push_back(p.first);
        }
        
        return ans;
    }
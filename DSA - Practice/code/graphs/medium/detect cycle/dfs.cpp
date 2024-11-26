/*

Solution: https://youtu.be/BPlrALf1LDU

*/

class Solution {
  
  void dfs(int V, vector<int> adj[], int start, int parent, vector<int>& vis, bool& ans) {
    
        if(ans) return;
    
        for(int child : adj[start]) {
            
            if(!vis[child]) {
                
                vis[child] = 1;
                dfs(V, adj, child, start, vis, ans);
            }
            else if(child != parent) {
                ans = true;
            }
        }  
  }
  
  
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> vis(V, 0);
        bool ans = false;
        
        // loop through all vertices because there could be disconnected graphs as well
        for(int i = 0; i < V; i++) {
            
            if(ans) return true;
            
            if(!vis[i]) {
                vis[i] = 1;
                dfs(V, adj, i, -1, vis, ans);
            }
        }
        
        return ans;
    }
};
class Solution {
  private:
  
  void dfs(int node, vector<int> adj[], int* visited, vector<int>& ans) {
      
      ans.push_back(node);
      visited[node] = 1;
      
      for(int i : adj[node]) {
          
          if(!visited[i]) {
              
              dfs(i, adj, visited, ans);
          }
      }
  }
  
  public:
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        int visited[V] = {0};
        vector<int> ans;
        
        dfs(0, adj, visited, ans);
        return ans;
    }


}
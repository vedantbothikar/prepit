  /*
  
  NOTES:
  
  - There is a reason why we mark the nodes as visited just before/after pushing the node in the queue and not before/after storing the element in the ans
  Reason is because it could be possible that the same element is considered twice and added to the queue two times, so it will be considered twice in the queue
  so to avoid this situation, we need to check if the element being added was already considered or not
  Copilot:
    The issue with your modified code is that you are marking nodes as visited only after popping them from the queue. This can lead to the same node being pushed into the queue multiple times before it is marked as visited, causing incorrect behavior.
To fix this, you should mark nodes as visited as soon as they are pushed into the queue. Here’s the corrected version of your code:
  
  
  */

    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        queue<int> q;
        vector<int> ans;
        vector<int> visited(V, 0);
        
        // push initial element
        q.push(0);
        visited[0] = 1;
        
        while(!q.empty()) {
            
            // pop element from queue
            int node = q.front();
            q.pop();
            
            // store answer
            ans.push_back(node);
            
            // push children of node to the queue and mark visited as true for them
            for(int i : adj[node]) {    // NOTE: we are iterating over adj[node] and not adj, that is because adj is an array of vectors and iterating over adj will give us vectors, but we want to iterate over the elements of adj[node]
                
                // if the element is not visited, push to queue and mark it as visited
                if(!visited[i]) {
                    
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
        
        return ans;
    }
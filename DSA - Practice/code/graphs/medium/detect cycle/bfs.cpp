#include<bits/stdc++.h>
using namespace std;


/*

- Solved using BFS
- Problem Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph

Cycle can be detected when we meet (visit) a particular node twice.
So, we need to perform BFS/DFS and check if we are meeting 
the same node twice or not.

It is simple logic, but when we perform BFS/DFS, same node comes
twice even if it is not a loop
For example, if a parent (A) has 2 children (B, C),
Now when I visit A (let's say in BFS) then I will add B and C
in the queue (since they are connected to each other in adjacency list)
Now when I visit B, I will add A and C to the queue (since these 2 are connected as per the adjacency list)
But the issue is we have already visited A
But since we have already visited A, that does not mean that there is a loop

So, we need to check that whenever we find an element that has PREVIOUSLY been visited, then we need to check 
HOW was the element visited previously. By HOW I mean, was the node
visited through the same parent or through someone else.
For example, in above scenario, we visited A twice, but the parent of the currentNode was equal to the child
currentNode: B
parent of currentNode: A
child of currentNode: A

So, whenever child != parent AND the node has been visited previously, THEN:
    THERE IS A LOOP



pair<int, int>
first: element
second: parent of element


if it is visited: check if it was parent, if yes, then:
    don't add to queue, continue bfs
    
if it is visited: if it was NOT parent, if yes, then:
    return true (cycle detected)

if NOT visited:
    visit and add to queue
    
    
    
___________________________________

For CONNECTED COMPONENTS:

Have a loop on the vertices, to check if all the elements have
been visited or not

If NOT visited:
    run bfs on that particular node
ELSE:
    keep going in the loop
    


*/



class Solution {

  private:
  
    bool bfs(int V, vector<int> adj[], int start, vector<int>& vis) {
        
        queue<pair<int, int>> q;
        
        q.push({start, -1});
        vis[start] = 1;
        
        while(!q.empty()) {
            
            pair<int, int> p = q.front();
            int node = p.first;
            int parent = p.second;
            
            q.pop();
            
            for(int child : adj[node]) {
                
                if(!vis[child]) {
                    
                    vis[child] = 1;
                    q.push({child, node});
                }
                else if (child != parent) {
                    // cycle detected
                    return true;
                }
            }
        }
        
        return false;
    }
    
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> vis(V, 0);
        
        // for checking for connected components
        for(int i = 0; i < V; i++) {
            
            if(!vis[i]) {
                
                if(bfs(i, adj, i, vis)) {   // send i as the start node 
                    return true;
                }
            }
        }
        
        return false;
    }
};
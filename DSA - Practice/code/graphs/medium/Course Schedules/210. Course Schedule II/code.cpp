/*

Topological Sorting/Ordering:

- https://leetcode.com/problems/course-schedule-ii/description/?envType=company&envId=salesforce&favoriteSlug=salesforce-three-months&status=TO_DO&difficulty=MEDIUM
- https://youtu.be/5lZ0iJMrUMk?si=mRIy30kPUMvXQwNw


Time Complexity: O(V+E)
Space Complexity: O(V+E)

*/


class Solution {

    // perform dfs on graph
    bool dfs(int currCourse, unordered_map <int, vector<int>>& adj, unordered_map <int, int>& visited, vector<int>& ans) {

        cout << "currCourse: " << currCourse << endl;

        // check if status is currently visiting
        if(visited[currCourse] == 1) {
            
            // has a cycle
            return false;
        }

        // alrready finished visiting and everything is fine
        if(visited[currCourse] == 2) {
            
            return true;
        }

        cout << "marking visiting" << endl;
        // mark current course as "currently visiting"
        visited[currCourse] = 1;

        // apply dfs on neighbours
        for(int neigh : adj[currCourse]) {

            cout << "neigh: " << neigh << endl;

            // return false if graph has a cycle
            if(!dfs(neigh, adj, visited, ans)) {
                
                return false;
            }
        }

        // mark as completely visited
        visited[currCourse] = 2;

        // push element to stack
        ans.push_back(currCourse);

        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map <int, vector<int>> adj;
        // create the adjacency list
        for(auto prereq : prerequisites) {

            adj[prereq[0]].push_back(prereq[1]);
        }

        // 0: not visited, 1: visiting currently, 2: finished visiting
        unordered_map <int, int> visited;

        vector<int> ans;

        // apply dfs on all courses
        for(int i = 0; i < numCourses; i++) {

            if(!dfs(i, adj, visited, ans)) {

                // cycle detected
                return {};
            }
        }

        return ans;
    }
};
/*

- https://leetcode.com/problems/course-schedule/
- https://neetcode.io/solutions/course-schedule

So essentially, if you find a cycle in the graph, then you cannot complete the courses, since there will be a deadlock kind of situation.

So we need to detect a cycle in the graph.

How to construct the graph?
- construct the adjacency list of the nodes
- keep a set to check if you have visited that node


So for every element in the adjacency list:
- perform dfs on it (on the adjancency list)
- check if we have already visited the pre-req nodes, if not, continue dfs on the pre-req nodes

TC: O(V+E)
SC: O(V+E)

*/
class Solution {

    bool dfs(int currCourse, vector<vector<int>>& prerequisites, unordered_set<int>& visited, unordered_map<int, vector<int>>& mp) {

        // base conditions: already visited
        if(visited.count(currCourse)) {
            return false;
        }

        // mark as visited
        visited.insert(currCourse);

        // visit all adjancent nodes of currCourse
        for(int prereq : mp[currCourse]) {

            if(!dfs(prereq, prerequisites, visited, mp)) {
                return false;
            }
        }

        // since no loop detected for currCourse: remove from set
        visited.erase(currCourse);

        // also delete adjacency list of currCourse: since there is no loop from here, we can ignore any future dfs on currCourse
        mp[currCourse].clear();

        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_set<int> visited;
        // map of each course with its prerequisites
        unordered_map<int, vector<int>> mp; 

        for(auto prereq : prerequisites) {
            
            mp[prereq[0]].push_back(prereq[1]);
        }

        // apply dfs to check loop for every course
        for(auto [currCourse, adjNodes] : mp) {

            if(!dfs(currCourse, prerequisites, visited, mp)) {
                return false;
            }
        }

        return true;
    }
};
/*

Problem Name: 3408. Design Task Manager
Problem Link: https://leetcode.com/problems/design-a-task-manager/

##############################

Data Structure 1 (DS1): priorities
ordered_map -> ordered_set
int -> {}
priority -> [taskId1, taskId2, ...]

Data Structure 2 (DS2): tasks
unordered_map
taskId1 -> (priority, userId)


##############################
ADD: O(logn)
    - add in DS2 => O(1)
    - insert in DS1 => O(logn)

Explanation of TC:
The operation touches two independent balanced trees:

map<int, set<int>> priorities
→ lookup/insertion into the map costs O(log P), where P = number of distinct priorities.

set<int> for that priority
→ inserting a taskId costs O(log S), where S = number of tasks with that priority.

Since these operations happen one after another, not nested inside each other, their costs add, giving: O(P + S) = O(n)

##############################    
REMOVE: O(logn)
    - find the priority from DS1 => O(1)
    - erase taskId from DS1 O(logn)
    - remove taskId from DS2 O(1)
    NOTE: When removing, please check if the ordered_set is empty. If it is empty, then delete the `priority` key from DS1.
##############################
EDIT: O(logn)
    - REMOVE
    - ADD
##############################
EXEC_TOP: O(logn)
    - get the highest priority => O(1)
    - get the highest taskId => O(1)
    - get the userId corresponding to the taskId => O(1)
    - REMOVE => O(logn)
##############################
CONSTRUCTOR: O(n * logn)
    - For tasks.size():
        - ADD
##############################


*/

# include <bits/stdc++.h>
using namespace std;

class TaskManager {

    map<int, set<int>> priorities;  // priority -> {taskId, ...}
    unordered_map<int, pair<int, int>> tasks;   // taskId -> {priority, userId}

public:
    TaskManager(vector<vector<int>>& tasks) {
        
        for(auto& task : tasks) {
            add(task[0], task[1], task[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        /*
            ADD: O(logn)
                - add in DS2 => O(1)
                - insert in DS1 => O(logn * logn)
        */

        // add in tasks
        tasks[taskId] = {priority, userId};

        // add in priorities
        priorities[priority].insert(taskId);
    }
    
    void edit(int taskId, int newPriority) {
        /*
            EDIT: O(logn)
                - REMOVE
                - ADD
        */

        // get the current userId
        pair<int, int> p = tasks[taskId];
        int userId = p.second;

        // remove
        rmv(taskId);

        // add 
        add(userId, taskId, newPriority);
    }
    
    void rmv(int taskId) {
        /*
            REMOVE: O(logn)
                - find the priority from DS1 => O(1)
                - erase taskId from DS1 O(logn)
                - remove taskId from DS2 O(1)
                NOTE: When removing, please check if the ordered_set is empty. If it is empty, then delete the `priority` key from DS1.
        */

        // find the priority
        pair<int, int> p = tasks[taskId];
        int priority = p.first;
        int userId = p.second;
        
        // remove task from priorities
        priorities[priority].erase(taskId);

        // check if current set is empty, if yes, erase key
        if(priorities[priority].empty()) {
            priorities.erase(priority);
        }

        // remove taskId from tasks
        tasks.erase(taskId);
    }
    
    int execTop() {
        /*
            EXEC_TOP: O(logn)
                - get the highest priority => O(1)
                - get the highest taskId => O(1)
                - get the userId corresponding to the taskId => O(1)
                - REMOVE => O(logn)
        */

        // if empty
        if(priorities.empty()) return -1;

        // get the highest priority
        auto it1 = priorities.end();
        --it1;
        int maxPriority = it1->first;

        // NOTE: the ordered set of this maxPriority cannot be empty
        // REASON: we are erasing the key if it is empty, in REMOVE function

        // get the highest taskId
        auto it2 = priorities[maxPriority].end();
        --it2;
        int maxTaskId = *it2;

        // get the corresponding userId
        pair<int, int> p = tasks[maxTaskId];
        int userId = p.second;

        rmv(maxTaskId);

        return userId;
    }


};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */

/*

- https://leetcode.com/problems/clone-graph/description/ 
- https://youtu.be/mQeF6bN8hMk?si=eDLBq5YpyDfQOwDv

*/


/*
# Approach

https://youtu.be/mQeF6bN8hMk?si=eDLBq5YpyDfQOwDv

In each iteration we are checking if we have already made a copy of that (by checking in the hashmap), if yes, then we just return that.
And if note we then make a copy of that node and append all neighbors as well.

Note that we put the node in the hashmap before adding the neighbors, that is because if we dont do this, it will go into infinite loop (think about it)

# Complexity
- Time complexity: O(V + E)
In the worst case, the graph is a connected graph, and the DFS traversal visits every node and every edge exactly once.

- Space complexity: O(V)

*/

# Code
```cpp []
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {

    Node* clone(Node* node, unordered_map<Node*, Node*>& mp) {

        // if the clone of the node exists, return as it is
        if(mp.find(node) != mp.end()) {
            return mp[node];
        }

        // if not, then create a deep copy
        Node* copy = new Node(node->val);
        mp[node] = copy;

        for(Node* neighbor : node->neighbors) {

            Node* neighborClone = clone(neighbor, mp);
            copy->neighbors.push_back(neighborClone);
        }

        return copy;
    }

public:
    Node* cloneGraph(Node* node) {

        // base condition: if node is NULL
        if(node == NULL) return NULL;

        unordered_map<Node*, Node*> mp;
        return clone(node, mp);
    }
};
```
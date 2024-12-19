/*

- https://leetcode.com/problems/copy-list-with-random-pointer/description/
- https://neetcode.io/solutions/copy-list-with-random-pointer

*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
/*
We can use a single hashmap to map the oldNode to the newNode

and then traverse the list for the second time and then map the oldNode's next and random pointers to the newNode pointers

*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        unordered_map <Node*, Node*> oldToNew;

        Node* oldNode = head;
        while(oldNode != nullptr) {

            // create copy
            Node* newNode = new Node(oldNode->val);

            // store in map
            oldToNew[oldNode] = newNode;

            // increment pointer
            oldNode = oldNode->next;
        }

        // traverse second time to deeop copy the next and random pointers
        oldNode = head;
        while(oldNode != nullptr) {

            Node* newNode = oldToNew[oldNode];
            
            // deep copy next and random
            if(oldNode->next != nullptr) {
                newNode->next = oldToNew[oldNode->next];
            }

            if(oldNode->random != nullptr) {
                newNode->random = oldToNew[oldNode->random];
            }

            oldNode = oldNode->next;
        }

        // this will give the Node* to newList's first node
        return oldToNew[head];
    }
};
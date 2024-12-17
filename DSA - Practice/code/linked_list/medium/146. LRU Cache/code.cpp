/*

- https://leetcode.com/problems/lru-cache/description/
- https://neetcode.io/solutions/lru-cache

We will have a doubly linkedlist that will maintain the order of elements as per using it

the starting will maintain the least recently used
and whenever we want to evict, we will evict from the beginning

and whenever there is a new element, we will insert at the end of the linked list

and simultaneoulsy we will also maintain a map to store the key value pairs.



get:
if value does not exist in map: return -1
if exists:
- remove node from list
- insert at the end in the list
- return the map value

put:
- if value did NOT exist previously
    - insert in map
    - insert in list
    - if maxSize has reached
        - remove lru node (beginning node)
- if value exists:
    - get the node from the map
    - update the value in the node
    - remove node from the list
    - insert at the end


TC: O(1) for get and put operations
SC: O(n)


*/

class Node {

public:
    int key;
    int value;

    Node* prev;
    Node* next;

    Node (int k, int v) {
        key = k;
        value = v;

        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {

    int maxSize;
    unordered_map <int, Node*> mp;
    Node* left;
    Node* right;

    void removeNode(Node* node) {
        /*
            - prev should point to next
            - next's prev should point to prev
        */

        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAtEnd(Node* node) {
        /*
            - last node's next should point to node
            - right's prev should point to node
            - node's prev should point to lastnode
            - node's next should point to right
        */

        Node* lastNode = right->prev;
        
        lastNode->next = node;
        right->prev = node;

        node->prev = lastNode;
        node->next = right;
    }

    void removeBeginNode() {
        /*
            - remove from list:
                - left's next should point to secondNode
                - secondNode's prev should point to left
                - delete firstNode
            - remove from map
        */

        Node* firstNode = left->next;
        Node* secondNode = firstNode->next;

        left->next = secondNode;
        secondNode->prev = left;

        mp.erase(firstNode->key);

        delete firstNode;
    }

public:
    LRUCache(int capacity) {
        /*
            - clear the map
            - initialize doubly linked list's left and right ends
        */

        mp.clear();
        maxSize = capacity;

        // initialize head and tail of doubly linked list
        left = new Node(0, 0);
        right = new Node(0, 0);
        
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        
        // if key does NOT exist
        if(mp.find(key) == mp.end()) {
            return -1;
        }

        // if key exists: remove from list, and insert at end
        Node* node = mp[key];
        removeNode(node);
        insertAtEnd(node);

        return node->value;
    }
    
    void put(int key, int value) {
        
        // key exists in map
        if(mp.find(key) != mp.end()) {

            Node* node = mp[key];
            node->value = value;
            removeNode(node);
            insertAtEnd(node);
        }
        else {  // new key to insert

            Node* node = new Node(key, value);
            mp[key] = node;

            insertAtEnd(node);

            if(mp.size() > maxSize) {
                removeBeginNode();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
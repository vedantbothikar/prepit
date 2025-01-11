class Node {

public:
    int key;
    int val;
    Node* next;

    Node(int k = -1, int v = -1, Node* n = nullptr) : key(k), val(v), next(n) {}
};

class MyHashMap {

    int hashNum;
    vector<Node*> mp;

    int hash(int key) {
        return key % hashNum;
    }

public:

    MyHashMap() {

        hashNum = 2069;
        mp.resize(hashNum);

        for(int i = 0; i < hashNum; i++) {
            mp[i] = new Node();
        }
    }
    
    void put(int key, int value) {

        int hashKey = hash(key);

        Node* curr = mp[hashKey];
        Node* prev;

        while(curr != nullptr) {

            // update if found
            if(curr->key == key) {
                curr->val = value;
                return;
            }

            prev = curr;
            curr = curr->next;
        }

        // if not found, prev will point to the last Node
        prev->next = new Node(key, value);
    }
    
    int get(int key) {
        
        int hashKey = hash(key);
        Node* curr = mp[hashKey];

        while(curr != nullptr) {

            if(curr->key == key) {
                return curr->val;
            }

            curr = curr->next;
        }

        return -1;
    }
    
    void remove(int key) {
        
        int hashKey = hash(key);
        Node* curr = mp[hashKey];

        // if key is at beginning
        if(curr->key == key) {
            mp[hashKey] = curr->next;
            return;
        }

        // key is NOT at beginning
        Node* prev = curr;
        curr = curr->next;

        while(curr != nullptr) {

            // if found, break the link and delete Node
            if(curr->key == key) {
                prev->next = curr->next;
                delete curr;
                return;
            }

            prev = curr;
            curr = curr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
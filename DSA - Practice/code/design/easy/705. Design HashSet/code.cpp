class Node {

    public:
    
        int key;
        Node* next;
    
        Node(int key) {
            this->key = key;
            next = nullptr;
        }
    };
    
    
    class MyHashSet {
    
        vector<Node*> hashSet;
        int hashNum;
    
        int hash(int key) {
            return key % hashNum;
        }
    
    public:
        MyHashSet() {
            
            // initialize the hashSet vector 
            hashNum = 2069;
            hashSet.resize(hashNum);
    
            for(int i = 0; i < hashNum; i++) {
                hashSet[i] = new Node(-1);
            }
        }
        
        void add(int key) {
    
            // first check if the key exists, if present, then return
            if(contains(key)) {
                return;
            }
            
            // key is NOT present. Add the key
            int hashKey = hash(key);
            Node* start = hashSet[hashKey];
    
            Node* newNode = new Node(key);
            Node* nextNode = start->next;
    
            start->next = newNode;
            newNode->next = nextNode;
        }
        
        void remove(int key) {
            
            // first check if key exists. If NOT, then return
            if(!contains(key)) {
                return;
            }
            
            // key is present. Remove it
            int hashKey = hash(key);
            Node* start = hashSet[hashKey];
    
            Node* prev = start;
            Node* curr = start->next;
    
            // loop and check where the key is present
            while(curr != nullptr) {
    
                if(curr->key == key) {
                    
                    // key found, remove it
                    Node* toRemove = curr;
                    Node* nextNode = curr->next;
    
                    prev->next = nextNode;
                    delete toRemove;
    
                    break;
                }
    
                prev = curr;
                curr = curr->next;
            }
    
            // key removed 
        }
        
        bool contains(int key) {
            
            int hashKey = hash(key);
            Node* start = hashSet[hashKey];
    
            // loop and check if key exists
            Node* curr = start;
    
            while(curr != nullptr) {
    
                if(curr->key == key) return true;
    
                curr = curr->next;
            }
    
            return false;
        }
    };
    
    /**
     * Your MyHashSet object will be instantiated and called as such:
     * MyHashSet* obj = new MyHashSet();
     * obj->add(key);
     * obj->remove(key);
     * bool param_3 = obj->contains(key);
     */
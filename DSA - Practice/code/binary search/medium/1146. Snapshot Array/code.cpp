/*

1146. Snapshot Array
Problem Link: https://leetcode.com/problems/snapshot-array/

hashap 
idx -> { {snapId, val}, ... }


*/
class SnapshotArray {

    unordered_map<int, map<int, int>> mp;
    int currSnapId;

public:
    SnapshotArray(int length) {
        currSnapId = 0;

        // populate all indices with value 0 as required in question
        for(int i = 0; i < length; i++) {
            mp[i][currSnapId] = 0;
        }
    }
    
    void set(int index, int val) {
        mp[index][currSnapId] = val;
    }
    
    int snap() {
        currSnapId++;   // goto next snapId
        return currSnapId - 1;
    }
    
    int get(int index, int snap_id) {
        
        /*
            To get the value at the snapId, we will check if the snapId exists
            in the inner map. 
            
            If snapId exists:
                return the value
            Else:
                get the next smaller value
                    How to do this?
                        - Get the upper bound (which means the new_snap_id > snap_id)
                        - decrement the iterator
        */

        // if snap_id exists
        if (mp[index].find(snap_id) != mp[index].end()) {
            return mp[index][snap_id];
        }

        // since the snap_id does NOT exist, get the next lower value

        auto it = mp[index].upper_bound(snap_id);

        // NOTE: the inner map will never be empty because 
        // we are already populating with value 0 in the constructor

        // decrement the iterator and return the value
        --it;

        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
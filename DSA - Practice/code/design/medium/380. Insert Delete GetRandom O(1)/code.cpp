/*

- Problem Link: https://leetcode.com/problems/insert-delete-getrandom-o1/



INSERT: 

Hashmap
val -> index


Array
store that element. this index will be used in the hashmap above.

O(1)
Since insertion at the end in array is O(1)
and insertion in hashmap is also O(1)


REMOVE:

We can easily remove from hashmap in O(1)
But removing from array, if its a middle element, then it could be linear time (because shifting elements).

What if we swap the element with the last element in thee array and then remove the last element. This way we can remove in O(1)



RANDOM:

We have the length of the array, so we can choose a random number and return that.




*/

class RandomizedSet {

    bool isValPresent(int val) {

        // if found
        if(mp.find(val) != mp.end()) return true;
        
        // else not found
        return false;
    }

public:

    unordered_map<int, int> mp;
    vector<int> arr;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        
        // return false if val is already present
        if(isValPresent(val)) return false;

        // insert val
        arr.push_back(val);
        int index = arr.size() - 1;
        mp[val] = index;

        return true;
    }
    
    bool remove(int val) {
        
        // return false if val is NOT present
        if(!isValPresent(val)) return false;

        // remove val
        int valIdx = mp[val];

        // swap indices (curr element and last element in arr)
        int lastIdx = arr.size() - 1;
        swap(arr[valIdx], arr[lastIdx]);

        // now val will be at lastIdx and swappedEle will be at valIdx

        // remove val from arr (now at last position)
        arr.pop_back();

        // update index of swapped element
        int swappedEle = arr[valIdx];
        int newSwappedEleIdx = valIdx;  // old valIdx will be newSwappedEleIdx
        mp[swappedEle] = newSwappedEleIdx;

        // remove val from mp
        mp.erase(val);

        return true;
    }
    
    int getRandom() {
        
        // get a random num within the range of arr and return the ele
        int randomNum = rand() % arr.size();
        return arr[randomNum];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
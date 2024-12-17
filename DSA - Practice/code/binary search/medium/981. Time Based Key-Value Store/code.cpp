/*
- https://leetcode.com/problems/time-based-key-value-store/description/
- https://neetcode.io/solutions/time-based-key-value-store

unordered_map <string, map<int, string>> mp

first string will store the key
int will store the timestamp
last string will store the value at the corresponding timestamp

the inner map is an ordered map while the outer one is an unordered map

the inner one is ordered because we will apply binary search for more optimized searching

TC:
get: O(logn) -> lower_bound
set: O(1)

SC: O(m*n)
Where n is the total number of unique timestamps associated with a key and m is the total number of keys.

*/
class TimeMap {
public:
    unordered_map <string, map<int, string>> mp;

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        
        map<int, string>& innerMp = mp[key];

        // if innerMp is empty
        if(innerMp.empty()) return "";

        auto it = innerMp.find(timestamp);
        // if timestamp key found
        if(it != innerMp.end()) {
            return it->second;
        }
        
        /*
        - if the timestamp does NOT exist, we need to get the greatest smaller timestamp available
        - to achieve this we will first find the lower bound of the timestamp which will give us the timestamp just greater that the one we want
        - then we will reduce the iterator one step and get the value of new key
        - BUT, it could be possible as edge case that the lower bound is found at the beginning and when we reduce the iterator by 1, we go out of bounds, so need to check for that case

        Also note, if all keys are smaller than currkey timestamp, then our lower bound will point to end() so when we do --lb, then we actually get the last value in the mp which is correct logic
        */

        auto lb = innerMp.lower_bound(timestamp);

        // if lower bound is at the beginning 
        if(lb == innerMp.begin()) {
            return "";
        }
        
        // go to prev timestamp
        --lb;
        return lb->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
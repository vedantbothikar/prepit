/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

/*

341. Flatten Nested List Iterator
Problem Link: https://leetcode.com/problems/flatten-nested-list-iterator/


- Instead of recursion we can use a stack to store the elements

TC: O(N) for flattening the list
SC: O(N) for storing the flattened list and recursion stack


*/


class NestedIterator {

    vector<int> flat;
    int currPos = 0;   // iterator position

    void flattenList(vector<NestedInteger> &nestedList) {

        for(auto n : nestedList) {
            
            // if single integer: just add to flat res
            if(n.isInteger()) {
                flat.push_back(n.getInteger());
            }
            else {
                flattenList(n.getList());
            }
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        
        flattenList(nestedList);
    }
    
    int next() {
        
        int val = flat[currPos];
        currPos++;

        return val;
    }
    
    bool hasNext() {
        
        if(currPos < flat.size()) return true;

        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
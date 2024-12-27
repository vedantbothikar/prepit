/*
- https://leetcode.com/problems/partition-labels/description/
- https://neetcode.io/solutions/partition-labels


The observation is that we will have to keep the size of the partition upto the last index of the multiple occurrences of the character we have chosen. 

Compute the last occurrence of each character in the string.
Use two pointers: one to track the start of the current partition and another to track the end of the partition based on the furthest last occurrence of characters encountered so far.

*/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        // populate map of lastIndex
        unordered_map<char, int> lastIndex;

        for(int i = 0; i < s.size(); i++) {
            lastIndex[s[i]] = i;
        }

        vector<int> ans;

        // traverse the string and compute the partitions
        int end = 0;
        int partSize = 0;
        for(int i = 0; i < s.size(); i++) {

            partSize++;
            end = max(end, lastIndex[s[i]]);

            // if partition is possible
            if(end == i) {
                ans.push_back(partSize);
                partSize = 0;
            }
        }

        return ans;
    }
};
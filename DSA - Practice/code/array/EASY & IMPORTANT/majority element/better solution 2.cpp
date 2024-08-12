#include <vector>
#include <unordered_map>

/*
HERE we are using HASHMAP


Time and Space Complexity:
Time Complexity: O(N), where N is the number of elements in the array. This is because we are iterating through the array once.
Space Complexity: O(N), due to the extra space required to store the counts of elements in the hashmap.



*/

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::unordered_map<int, int> countMap;
        int majorityCount = nums.size() / 2;
        
        for (int num : nums) {
            countMap[num]++;
            if (countMap[num] > majorityCount) {
                return num;
            }
        }
        
        // Since the problem guarantees that a majority element always exists,
        // we do not need to handle the case where no majority element is found.
        return -1; // This line will never be reached.
    }
};

/*

- https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/



Approach:

2 pointers, sliding window, hashmap

Logic is to keep adding elements in map to check if we are storing unique elements, until the point we reach the size k. On reaching size k, compare with maxSum and slide the window

Traverse the array sequentially,
- if element exists in map
    - reduce the currentSum since you are removing elements from the left
    - slide the window such that the start pointer goes one ahead of element repeated
    - keep erasing elements from hashmap that are not present in the window now
- else if new element
    - add in map
    - add to currentSum
    - if currentSize of subarray == k
        - compare currentSum with maxSum
        - slide the window
            - remove element from hashmap
            - move the start pointer ahead

unordered_map<int, int> mp; // {nums[i], i} which means the number will be mapped to the index of the element in the array


Complexity
Time complexity: O(n)
Space complexity: O(k) // The space complexity is primarily determined by the unordered_map mp, which can store up to k unique elements in the worst case.

*/

using ll = long long;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        ll currentSum = 0;
        ll maxSum = 0;
        unordered_map<int, int> mp;

        int left = 0;
        for(int right = 0; right < n; right++) {

            int currentElement = nums[right];

            // element found in map
            if(mp.find(currentElement) != mp.end()) {

                while(mp.find(currentElement) != mp.end()) {

                    // slide window
                    currentSum -= nums[left];
                    mp.erase(nums[left]);
                    left++;
                }
            }

            // add the unique element
            currentSum += currentElement;
            mp[currentElement] = right;

            if(right - left + 1 == k) {

                maxSum = max(maxSum, currentSum);

                // slide the window
                currentSum -= nums[left];
                mp.erase(nums[left]);
                left++;
            }

        }

        return maxSum;
    }
};
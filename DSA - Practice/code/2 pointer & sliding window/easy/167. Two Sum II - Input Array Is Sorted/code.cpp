
/*
167. Two Sum II - Input Array Is Sorted
- https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/


# Approach
<!-- Describe your approach to solving the problem. -->

What do we understand?
- index1 < index2
- arr[i1] + arr[i2] = target
- sorted array

-----------

Brute force:
- Two loops
    - first loop from i = 0 to n-2
    - second loop from j=i + 1 to j=n-1
    - In each iteration check the sum of arr[i] + arr[j]

TC: O(N^2)
SC: O(1)

---

Better:

Can we have 2 pointers?
start from i = 0, j = n-1 (like start and end pointers)
if arr[start] + arr[end] > target:
    end--
else if arr[start] + arr[end] < target:
    start++;
else if arr[start] + arr[end] == target:
    return {start, end}

TC: O(N)
SC: O(1)


# Complexity
- Time complexity: O(N)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(1)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        
        int n = arr.size();
        int start = 0, end = n-1;

        while (start < end) {

            if(arr[start] + arr[end] == target) {
                return {start+1, end+1};    // 1 based indexing
            }
            else if(arr[start] + arr[end] < target) {
                start++;
            }
            else {
                end--;
            }
        }

        return {};
    }
};

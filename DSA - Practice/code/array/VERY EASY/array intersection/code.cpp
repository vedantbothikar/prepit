/*


- https://leetcode.com/problems/intersection-of-two-arrays/description/
- https://leetcode.com/problems/intersection-of-two-arrays/solutions/5913802/c-solution-using-2-sets/


Time Complexity:
Storing the elements of the first array in a set: This takes O(N), where N is the size of the first array. Inserting elements into a set (which is a hash-based data structure) takes constant time on average (O(1) per insertion).
Traversing the second array and checking membership in the set: This also takes O(M), where M is the size of the second array. Checking membership in a set takes constant time on average (O(1)), and so does removing an element from the set.

So, the total time complexity is O(N + M), which simplifies to O(N) in the best case, where N is the size of the larger array.

Space Complexity:
The space complexity is O(N), where N is the number of unique elements in the first array, because the set stores all unique elements of the first array.




*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        // store all unique elements of nums1 in set s
        unordered_set<int> s (nums1.begin(), nums1.end());

        // declare another set to add elements from nums2
        // NOTE: here we declared another set and not vector<int> because nums2 can also have duplicates, so if s has the number let's say '2' and nums2 has two '2's, then vector would have stored two 2s, that is why we need a set here as well
        unordered_set<int> ansSet;

        for(int num : nums2) {
            if(s.count(num) > 0) {
                ansSet.insert(num);
            }
        }

        // Convert set to vector for returning the result
        return vector<int>(ansSet.begin(), ansSet.end());
    }
};
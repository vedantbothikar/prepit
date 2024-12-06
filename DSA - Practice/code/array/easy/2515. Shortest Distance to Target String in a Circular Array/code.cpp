/*

- https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/
- 

if target does NOT exist:
return -1

if target exists:
shortest distance from current position to reach the target

options:
- go right and check
- go left and check

When to stop going right, when to stop going left?
    - when we reach the same element again, like a circle

*/
class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        
        int n = words.size();
        int minDis = INT_MAX;

        // when i = n, we will reach the same element again in the circle
        for(int i = 0; i < n; i++) {

            int rightPos = (startIndex + i) % n;
            int leftPos = (startIndex - i + n) % n;

            if(words[rightPos] == target) {
                minDis = min(minDis, i);
            }

            if(words[leftPos] == target) {
                minDis = min(minDis, i);
            }
        }
        
        return minDis == INT_MAX ? -1 : minDis;
    }
};
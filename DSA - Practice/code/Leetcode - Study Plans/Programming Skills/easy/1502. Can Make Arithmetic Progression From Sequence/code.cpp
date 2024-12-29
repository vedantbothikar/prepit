/*

- https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/?envType=study-plan-v2&envId=programming-skills
- 1502. Can Make Arithmetic Progression From Sequence

Sorting:
sorting, and then check the difference between every consecutive elements
O(nlogn)


Set:
- without sorting, insert all elements in a set

diff = (max_value - min_value) / (n - 1)

start from min value and keep checking if the next value is present or not

TC: O(n)

*/
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        
        int n = arr.size();

        int minVal = *min_element(arr.begin(), arr.end());
        int maxVal = *max_element(arr.begin(), arr.end());

        // base conditions
        if(maxVal - minVal == 0) return true;

        if((maxVal - minVal) % (n-1) != 0) return false;

        unordered_set<int> s;
        for(int num : arr) {
            s.insert(num);
        }

        int diff = (maxVal - minVal) / (n-1);

        for(int i = 0; i < n; i++) {
            
            int num = minVal + (i * diff);
            if(s.find(num) == s.end()) return false;
        }

        return true;
    }
};
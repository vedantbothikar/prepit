/*

APPROACH:

- Sort the array in O(NlogN)
- Keep two counters: max and curr
- Traverse the array and count the elements of current element, curr+ and so on
- When you reach to an element that is not equal to next element, then max =
max(max, curr)
- Finally return max


Here our max time complexity if for sorting which is O(NlogN)
Also we are using constant space complexity


*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        sort(nums.begin(), nums.end()); // sort in O(NlogN)

        int maxCount = 0;
        int ElementWithMaxCount = 0;
        int currCount = 0;

        // process for 0th element
        int prevElement = nums[0];
        ElementWithMaxCount = nums[0];
        currCount = 1;

        // start from 1st element
        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] != prevElement) {

                if (currCount > maxCount) {

                    ElementWithMaxCount = prevElement;
                    maxCount = currCount;
                }
                currCount = 1;
            }

            if (nums[i] == prevElement)
                currCount++;

            prevElement = nums[i];
        }

        // if last element is of maxCount
        if (currCount > maxCount) {

            int last = nums.size()-1;
            ElementWithMaxCount = nums[last];
            maxCount = currCount;
        }

        return ElementWithMaxCount;
    }
};
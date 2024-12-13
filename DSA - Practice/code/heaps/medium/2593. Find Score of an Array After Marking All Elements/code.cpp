/*

- https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/


We want to:
1] find the min element everytime
2] mark the elements (which means not consider the marked ones)

For 1st we can use a minheap
For 2nd we can use a set in which we will store the marked elements

Algorithm:
We will take min element from heap
If it is not marked: (do this by checking in the set)
    - add to score
    - add current & both adjacent elements to set


- set of pair of element,index



How to handle the case when there are multiple min elements?
- we have to choose the one with smaller index
    - minheap with pair of ele & index


TC: O(nlogn)
- adding in set: O(1)
- adding elements in heap: O(nlogn)

SC: O(n)
- set
- minheap

Here instead of set we can also use a vector of bool to mark them

*/
class Solution {
public:
    long long findScore(vector<int>& nums) {

        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;

        vector<bool> marked(nums.size(), false);

        // push elements to nums
        for(int i = 0; i < nums.size(); i++) {
            minheap.push({nums[i], i});
        }

        long long score = 0;
        while(!minheap.empty()) {

            pair<int, int> p = minheap.top();
            int num = p.first;
            int index = p.second;

            // if marked element
            if(marked[index] == true) {
                // pop and ignore
                minheap.pop();
                continue;
            }

            // unmarked element: update score and mark elements
            score += num;
            
            // mark elements
            marked[index] = true;

            int left = index-1;
            int right = index+1;

            if(left >= 0) {
                marked[left] = true;
            }

            if(right < nums.size()) {
                marked[right] = true;
            }
        }
        
        return score;
    }
};
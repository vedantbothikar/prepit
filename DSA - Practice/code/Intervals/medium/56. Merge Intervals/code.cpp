/*

- https://leetcode.com/problems/merge-intervals/
- https://youtu.be/44H3cEC2fFM?si=pE0Js9cXm8BWuu17


Complexity
- Time complexity: O(nlogn)
- Space complexity: O(n)

*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());   // sort based on the start times

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for(int i = 1; i < n; i++) {

            int ansSize = ans.size();
            int prevEndTime = ans[ansSize - 1][1];  // take the endTime of last interval in ans

            // clash
            if(intervals[i][0] <= prevEndTime) {  // currentStartTime <= prevEndTime
                
                // merge: change endTime of the interval stored in the ans
                ans[ansSize - 1][1] = max(ans[ansSize - 1][1], intervals[i][1]);    // store max of both endTimes
            }
            else {  // case: no clash of times
                
                ans.push_back(intervals[i]);
            }

        }

        return ans;
    }
};
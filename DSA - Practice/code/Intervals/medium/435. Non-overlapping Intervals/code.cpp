/*

- https://leetcode.com/problems/non-overlapping-intervals/
- https://youtu.be/nONCGxWoUfM?si=L3c65nfuui-QZm4N




- sort based on the startTimes
- keep a prevInterval vector
- if current startTime is less than prevInterval endTime: there is a clash
    - remove the interval with the higher endTime: greedy approach

Complexity
- Time complexity: O(nlogn)
- Space complexity: O(1)

*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int numOfIntervalsRemoved = 0;

        if(n == 1) return 0;

        vector<int> prev = intervals[0];
        for(int i = 1; i < n; i++) {

            // clash
            if(intervals[i][0] < prev[1]) {

                // remove the one with higher endTime
                if(prev[1] > intervals[i][1]) {
                    
                    prev = intervals[i];    // pick one with shorter endTime
                }

                numOfIntervalsRemoved++;
            }
            else {  // no clash

                prev = intervals[i];
            }
        }

        return numOfIntervalsRemoved;
    }
};
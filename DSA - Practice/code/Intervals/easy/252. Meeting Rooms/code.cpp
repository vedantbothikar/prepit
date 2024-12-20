/*

- https://leetcode.com/problems/meeting-rooms/description/
- https://neetcode.io/solutions/meeting-rooms

to determine if we could attend all meetings, we need to check for any overlapping meetings.

So if we first sort it based on the start time and then check if the starttime of current meeting overlaps with the endTime of previous meeting, we can find collision

TC: O(nlogn)
SC: O(1)

*/
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {

        int n = intervals.size();
        if(n == 0) return true;

        // sort based on start time
        sort(intervals.begin(), intervals.end());

        int prevEndTime = intervals[0][1];
        for(int i = 1; i < n; i++) {
            
            int startTime = intervals[i][0];
            if(startTime < prevEndTime) {
                return false;
            }

            prevEndTime = intervals[i][1];
        }

        return true;
    }
};
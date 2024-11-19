/*

- https://leetcode.com/problems/insert-interval/description/


First insert all intervals that are not clashing
Second merge intervals that clash
Third insert all remaining intervals that dont clash

How to check if intervals are not clashing at the start?
- Wherever the endTime of original interval is less than the startTime of the newInterval

How to check if intervals are clashing?
- Wherever it clashes, the endTime of the newInterval will be greater than the startTime of the original interval

How to merge these intervals?
- Take the min of startTimes of both the intervals
- Take the max of endTimes of both the intervals

*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int index = 0;
        int n = intervals.size();
        vector<vector<int>> ans;

        // base condition:
        if(n == 0) {
            return {newInterval};
        }

        // initial non clashing
        while(index < n && intervals[index][1] < newInterval[0]) {

            ans.push_back(intervals[index]);
            index++;
        }

        cout << "index is: " << index << endl;

        // clashing: merge
        while(index < n && newInterval[1] >= intervals[index][0]) {

            cout <<"entering clash loop: " << index << endl;
            newInterval[0] = min(newInterval[0], intervals[index][0]);
            newInterval[1] = max(newInterval[1], intervals[index][1]);

            index++;
        }

        ans.push_back(newInterval);

        // ending all non clashing
        while(index < n) {

            ans.push_back(intervals[index]);
            index++;
        }
        
        return ans;
    }
};
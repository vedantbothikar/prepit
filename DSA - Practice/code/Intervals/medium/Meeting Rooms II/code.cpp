/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

/*

- https://neetcode.io/problems/meeting-schedule-ii
- https://youtu.be/FdzJmTCVyJU

The number of days can be found by checking 
at maximum how many meetings overlap at one point in time.


sort startTimes and endTimes separately

We can use a 2 pointer technique, 
if the startTime < endTime:
    // there is an overlap
    count++     
    startptr++;  
else:   
    endptr++
    count--


count holds the number of meetings going on at the current point of time
we will return the max value that count ever holds

- TC: O(nlogn)
- SC: O(n)


*/
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        
        // separate out start and end times
        vector<int> startTimes, endTimes;
        for(auto interval : intervals) {

            startTimes.push_back(interval.start);
            endTimes.push_back(interval.end);
        }

        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());

        int maxCount = 0;
        int count = 0;  // count of no of meets overlapping right now

        int n = startTimes.size();
        int startptr = 0, endptr = 0;
        while(startptr != n) {

            // if meetings overlap
            if(startTimes[startptr] < endTimes[endptr]) {
                
                count++;
                startptr++;
            }
            else {

                count--;
                endptr++;
            }

            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};

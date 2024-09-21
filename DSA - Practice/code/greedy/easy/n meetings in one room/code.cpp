/*

problem: https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
solution: https://www.youtube.com/watch?v=mKfhTotEguk

Sort based on the end time of the meetings
Take the greedy approach:

Take the meeting which ends first
Then choose the next
    - only if the startTime of next meeting < endTime of previous meeting

*/



class Solution {
    
    static bool comparator(pair<int, int> m1, pair<int, int> m2) {
        return m1.second < m2.second;
    }
    
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        
        // store the pair of start and end in a vector
        vector<pair<int, int>> meetings;
        
        for(int i = 0; i < n; i++) {
            
            meetings.push_back({start[i], end[i]});
        }
        
        // sort on the basis of endTime
        sort(meetings.begin(), meetings.end(), comparator);
        
        int count = 0;
        
        // add the first meeting
        int prevMeetEndTime = meetings[0].second;
        count++;
        
        // start the greedy approach
        for(int i = 1; i < meetings.size(); i++) {
            
            if(meetings[i].first > prevMeetEndTime) {
                count++;
                prevMeetEndTime = meetings[i].second;
            }
        }
        
        return count;
    }
};
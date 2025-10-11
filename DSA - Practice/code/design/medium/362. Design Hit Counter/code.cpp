/*



    362. Design Hit Counter
    Problem Statement: https://leetcode.com/problems/design-hit-counter/
    Difficulty: Medium
    Topic: Design

    NOTE:
Similar to 933. Number of Recent Calls
Link: https://leetcode.com/problems/number-of-recent-calls/



*/

class HitCounter {

    int total;
    queue<pair<int, int>> q;    // {timestamp, total}

public:
    HitCounter() {
        total = 0;
    }
    
    void hit(int timestamp) {
        
        // if the timestamp exists, increment the hit
        // else add a new pair

        if(q.empty() or q.back().first != timestamp) {
            q.push({timestamp, 1});
        }
        else {
            q.back().second++;
        }


        total++;
    }
    
    int getHits(int timestamp) {
        
        // remove all timestamps with diff greater than 300
        while(!q.empty()) {

            int frontTimestamp = q.front().first;
            int diff = timestamp - frontTimestamp;

            if(diff >= 300) {
                // remove the entry
                total = total - q.front().second;
                q.pop();
            }
            else {
                // break if we found the correct position to start with
                break;
            }
        }

        return total;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
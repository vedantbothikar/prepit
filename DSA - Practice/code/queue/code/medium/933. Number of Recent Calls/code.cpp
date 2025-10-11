/*

933. Number of Recent Calls
https://leetcode.com/problems/number-of-recent-calls/description/


*/

class RecentCounter {

    int total;
    queue<int> q;

public:
    RecentCounter() {
        total = 0;
    }
    
    int ping(int t) {

        // add the request in the queue
        q.push(t);
        total++;

        // get the total requests in past 3000 milliseconds
        while(!q.empty()) {
            
            int frontTime = q.front();
            if(t - frontTime > 3000) {  // timestamps older than 3000
                // delete
                q.pop();
                total--;
            }
            else {
                break;
            }

        }

        return total;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
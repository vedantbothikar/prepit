/*

Problem Name: 359. Logger Rate Limiter
Problem Link: https://leetcode.com/problems/logger-rate-limiter/description/?envType=problem-list-v2&envId=design

We have to store the messages and their timestamp.
Note timestamp doesn't reset, so we have to use the initial timestamp only.


If message not present in mp:
    - add it
    - print it (return true)

Else: (message present):
    - if currTime - mp[msg] < 10:
        - dont print (return false)
    - else:
        - update to latest timestamp
        - print (return true)




*/
class Logger {

    unordered_map<string, int> msgs;

public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        
        // msg not found
        if(msgs.find(message) == msgs.end()) {
            msgs[message] = timestamp;
            return true;
        }

        // msg found
        // check time difference
        int timeDiff = timestamp - msgs[message];
        if(timeDiff < 10) return false;

        // update to latest timestamp and return true
        msgs[message] = timestamp;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
/*


Problem Link: https://leetcode.com/problems/design-a-leaderboard/


map<playerId, score>    // we can addScore
vector<{score, playerId}>    // we can get topK



*/
class Leaderboard {

    unordered_map<int, int> mp;

public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        
        // if playerId does NOT exist: set the value to score
        if(mp.find(playerId) == mp.end()) {
            mp[playerId] = score;
            return;
        }

        // if the playerId exists, add the score
        mp[playerId] += score;
    }
    
    int top(int K) {
        
        // to get the top K scores, we will use a min-heap
        // we will first add K elements to the min heap
        // then while adding rest N-K elements, we remove the smallest ones
        // this is how we are left with top K scores
        // then simply sum the minheap

        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto &x : mp) {
            int score = x.second;
            pq.push(score);

            // if pq size is greater than K, remove the smallest (top)
            if(pq.size() > K) {
                pq.pop();
            }
        }

        // sum all scores in pq
        int sum = 0;
        while(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
    
    void reset(int playerId) {
        mp.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
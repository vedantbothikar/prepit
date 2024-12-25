/*

- https://leetcode.com/problems/detect-squares/
- https://neetcode.io/solutions/detect-squares


TC: 
O(1) for addition
O(n) for counting

SC: O(n) for map

*/


class DetectSquares {
public:

    unordered_map<int, unordered_map<int, int>> ptsCount; // {x -> {y -> count}}

    DetectSquares() {
        
        ptsCount.clear();
    }
    
    void add(vector<int> point) {
        
        int x = point[0];
        int y = point[1];

        ptsCount[x][y]++;
    }
    
    int count(vector<int> point) {
        
        int x1 = point[0], y1 = point[1];
        int totSqs = 0;

        for(auto& [y2, currCnt] : ptsCount[x1]) {

            int sideLen = abs(y2 - y1);
            
            if(sideLen == 0) continue;

            // check for squares on left and right
            int x3 = x1 - sideLen;
            int x4 = x1 + sideLen;

            // multiply counts of all 3 coordinates
            totSqs += currCnt * ptsCount[x3][y1] * ptsCount[x3][y2];
            totSqs += currCnt * ptsCount[x4][y1] * ptsCount[x4][y2];
        }

        return totSqs;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
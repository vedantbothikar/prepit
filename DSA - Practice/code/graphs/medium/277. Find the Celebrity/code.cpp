/* 

https://leetcode.com/problems/find-the-celebrity/

    Problem Statement: https://leetcode.com/problems/find-the-celebrity/
    Difficulty: Medium
    Topic: Graphs



The knows API is defined for you.
      bool knows(int a, int b); 
      
    */

class Solution {

    bool isCelebrity(int x, int n) {

        // we need to check if x does NOT know anyone
        // and everyone knows x

        for(int i = 0; i < n; i++) {

            if(i == x) continue;     // ignore this case

            if(knows(x, i) or !knows(i, x)) return false;
        }

        return true;
    }

public:
    int findCelebrity(int n) {
        
        // consider first candidate as the celebrity
        // and then check if it is the one
        // if not, then assign the next one 

        int candidate_celebrity = 0;
        for(int i = 1; i < n; i++) {

            if(knows(candidate_celebrity, i)) {
                // if celebrity knows i, that means
                // our chosen candidate_celebrity is the wrong one
                candidate_celebrity = i;
            }
        }

        // finally check if it is actually a celebrity
        if(isCelebrity(candidate_celebrity, n)) return candidate_celebrity;

        return -1;
    }
};
/*

- problem: https://leetcode.com/problems/broken-calculator/
- solution: watch online, or chatgpt
*/

class Solution {

private: 

    int solve(int start, int target) {

        // base case
        if(start >= target) return start - target;

        if(target % 2 == 0) return 1 + solve(start, target/2);
        else return 1 + solve(start, target + 1);
    }

public:
    int brokenCalc(int start, int target) {

        return solve(start, target);
    }
};
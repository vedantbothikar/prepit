/*

- https://leetcode.com/problems/robot-return-to-origin/description/?envType=study-plan-v2&envId=programming-skills

*/

class Solution {
public:
    bool judgeCircle(string moves) {

        int topDown = 0;
        int leftRight = 0;

        for(char ch : moves) {

            if(ch == 'U') topDown++;
            else if(ch == 'D') topDown--;
            else if(ch == 'R') leftRight++;
            else if(ch == 'L') leftRight--;
        }
        
        return !topDown && !leftRight;
    }
};
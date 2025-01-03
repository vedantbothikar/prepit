/*

- https://leetcode.com/problems/robot-bounded-in-circle/?envType=study-plan-v2&envId=programming-skills

x, y, direction

Final vector: position and direction of the robot after completing all steps once.

On observation:
There is loop, ONLY if the robot changes direction or it again comes back to (0,0)



*/
class Solution {

    unordered_map<char, char> leftDir = {
        {'N', 'W'},
        {'W', 'S'},
        {'S', 'E'},
        {'E', 'N'},
    };

    unordered_map<char, char> rightDir = {
        {'N', 'E'},
        {'E', 'S'},
        {'S', 'W'},
        {'W', 'N'},
    };

    void applyGOp(int& x, int& y, char& direction) {

        if(direction == 'N') {
            y++;            
        }
        else if(direction == 'S') {
            y--;
        }
        else if(direction == 'E') {
            x++;
        }
        else if(direction == 'W') {
            x--;
        }
    }

    void applyDirectionOp(char& currDir, char& turn) {
        
        if(turn == 'L') {
            currDir = leftDir[currDir];
        }
        else if(turn == 'R') {
            currDir = rightDir[currDir];
        }
    }

public:
    bool isRobotBounded(string instructions) {
        
        int x = 0, y = 0;
        char direction = 'N';

        // apply all operations
        for(char instr : instructions) {

            if(instr == 'G') {
                applyGOp(x, y, direction);
            }
            else if(instr == 'L' or instr == 'R') {
                applyDirectionOp(direction, instr);
            }

        }

        // if we are back to (0,0) or we have changed direction: LOOP present
        if((x == 0 and y == 0) or direction != 'N') return true;

        return false;
    }
};
/*

- https://leetcode.com/problems/check-if-it-is-a-straight-line/description/?envType=study-plan-v2&envId=programming-skills


READ:
- https://gist.github.com/vedantbothikar/d7b13eff7968c71abfa45773d867ad54

the slope of point1 and point2 should match with slope of point1 and point3

So,

(y2 - y1)       (y3 - y1)
_________  =   ___________

(x2 - x1)       (x3 - x1)



Which we can reduce to ->
(y2-y1) * (x3-x1) = (y3-y1) * (x2-x1)



*/
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {

        int x1 = coordinates[0][0];
        int y1 = coordinates[0][1];

        int x2 = coordinates[1][0];
        int y2 = coordinates[1][1];

        for(int i = 2; i < coordinates.size(); i++) {

            int x3 = coordinates[i][0];
            int y3 = coordinates[i][1];

            // check if slopes match
            if((y2-y1) * (x3-x1) != (y3-y1) * (x2-x1)) return false;

        }

        return true;
    }
};
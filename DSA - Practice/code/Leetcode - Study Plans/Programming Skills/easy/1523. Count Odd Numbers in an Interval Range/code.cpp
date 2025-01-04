/*

- https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/?envType=study-plan-v2&envId=programming-skills

3 4 5 6 7

(7-3) / 2   + 1

(10-8)/2 

(11-8)/2 + 1

(11-9)/2 + 1


*/
class Solution {
public:
    int countOdds(int low, int high) {

        if(low % 2 == 0 and high % 2 == 0) {
            return (high-low)/2;
        }

        return (high-low)/2 + 1;
    }
};
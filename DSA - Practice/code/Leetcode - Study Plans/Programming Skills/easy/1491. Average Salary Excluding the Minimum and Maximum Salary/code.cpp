/*

- https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/description/?envType=study-plan-v2&envId=programming-skills
*/

class Solution {
public:
    double average(vector<int>& salary) {

        int n = salary.size();
        int maxSal = INT_MIN;
        int minSal = INT_MAX;
        int sum = 0;

        for(int x : salary) {
            
            sum += x;
            minSal = min(minSal, x);
            maxSal = max(maxSal, x);
        }

        return (double) (sum - minSal - maxSal) / (double) (n-2);
        
    }
};
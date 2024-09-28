/*

- problem: https://leetcode.com/problems/powx-n/submissions/1404403255/


*/


class Solution {

public:
    double myPow(double x, int n) {

        double ans = 1.0;
        long long nn = n;
        if (n < 0) nn = -1 * nn;

        while(nn > 0) {

            if(nn % 2 == 1) {    // n is odd
                ans = ans * x;
                nn = nn - 1;
            }
            else {
                x = x * x;
                nn = nn / 2;
            }
        }

        // handle case when n is negative
        if(n < 0) ans = (double) (1.0) / (double) (ans);

        return ans;
    }
};
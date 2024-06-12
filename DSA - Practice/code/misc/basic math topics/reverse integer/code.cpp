
// Full solution explained here:
// READ: https://leetcode.com/problems/reverse-integer/solutions/5296329/c-all-tests-passed-with-detailed-explanation/



class Solution {
public:
    int reverse(int x) {
        
        int ans = 0;

        while(x != 0){

            int lastDigit = x % 10;

            // check for positive overflow
            if(ans > INT_MAX/10 or (ans == INT_MAX/10 and lastDigit > INT_MAX%10)){
                return 0;
            }

            // check for negative overflow
            if(ans < INT_MIN/10 or (ans == INT_MIN/10 and lastDigit < INT_MIN%10)){
                return 0;
            }

            ans = (ans*10) + lastDigit;

            x = x / 10;
        }

        return ans;
    }
};
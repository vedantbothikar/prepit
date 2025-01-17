/*

- https://leetcode.com/problems/confusing-number/submissions/1511055518/?envType=study-plan-v2&envId=programming-skills

Steps:
- rotate 180 degrees 
- check if valid

rotate means we have to reverse the number

but first we should check if the reverse would be a valid number or not
Valid conditions:
- 2,3,4,5,7 => INVALID

So, we will have to check each digit one by one
if any of invalid nums present: return false
else:
    rotate the number and add to result


*/
class Solution {

    bool isDigitInvalid(int digit) {

        if(digit == 2 or digit == 3 or digit == 4 or digit == 5 or digit == 7) return true;

        return false;
    }

    int rotateDigit(int digit) {

        if(digit == 0) return 0;
        if(digit == 1) return 1;
        if(digit == 6) return 9;
        if(digit == 8) return 8;
        if(digit == 9) return 6;

        return -1;
    }

public:
    bool confusingNumber(int n) {

        int ogNum = n;
        long long ans = 0;

        while(n) {

            int digit = n % 10;
            n = n / 10;

            if(isDigitInvalid(digit)) {
                return false;
            }

            // valid digit: rotate 
            int rotatedDigit = rotateDigit(digit);
            ans = (ans * 10) + rotatedDigit;
        }

        if((long long) ogNum == ans) {
            return false;
        }

        return true;
    }
};
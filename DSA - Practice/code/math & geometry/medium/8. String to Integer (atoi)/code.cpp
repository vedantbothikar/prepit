/*

- https://leetcode.com/problems/string-to-integer-atoi/description/


Step1: Keep reading until you have non-whitespace character

Step2: Check if it is a negative or positive character. If none of them, assume positive

Step3: read characters until non-digit character or end of string.


Questions:
- How to check if it is a digit character?
    str[i] >= '0' and str[i] <= '9'

- How to maintain the int version of the ans?
    long long ans = 0;
    int digit = str[i] - '0'
    ans = (ans*10) + digit;

- How to handle out of bounds issue?
    - lets keep ans as long long
    - after calculating the final answer, we can compare it with INT_MIN and INT_MAX to check what to return


*/
class Solution {

    void ignoreWhitespaces(string s, int& index) {

        int n = s.size();

        while(index < n and s[index] == ' ') {
            index++;
        }
    }

    bool checkSign(string s, int& index) {

        if(s[index] == '-') {
            index++;
            return false;
        }

        if(s[index] == '+') {
            index++;
            return true;
        }

        return true;
    }

public:
    int myAtoi(string s) {
        
        long long ans = 0;
        int index = 0;

        int n = s.size();
        bool positive = true;

        // Step 1
        ignoreWhitespaces(s, index);
        if(index >= n) return 0;

        // Step 2
        positive = checkSign(s, index);
        if(index >= n) return 0;

        cout << "positive: " << positive << endl;

        // Step 3
        while(index < n) {

            char ch = s[index];

            // check if character is NOT a digit, break
            if(!(ch >= '0' and ch <= '9')) break;

            int digit = ch - '0';
            ans = (ans * 10) + digit;

            // doing this here as well, because even long long could go out of bounds
            if(ans > INT_MAX) {

                if(!positive) ans = (-1) * ans;
                if(ans <= INT_MIN) return INT_MIN;
                if(ans >= INT_MAX) return INT_MAX;
            }

            index++;
        }

        // Use the sign
        if(!positive) {
            ans = (-1) * ans;
        }

        // Check out of bounds
        if(ans < INT_MIN) {
            ans = INT_MIN;
        }
        else if(ans > INT_MAX) {
            ans = INT_MAX;
        }

        return ans;
    }
};
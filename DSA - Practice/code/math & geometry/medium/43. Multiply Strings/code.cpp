/*

Problem Link: https://leetcode.com/problems/multiply-strings/
Solution: https://neetcode.io/solutions/multiply-strings


USELESS QUESTION

*/

class Solution {
public:
    string multiply(string num1, string num2) {

        if(num1 == "0" or num2 == "0") return "0";

        int n = num1.size();
        int m = num2.size();

        // reverse
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        // create ans vector of size n+m
        vector<int> ans(n + m, 0);

        // multiply each number
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                int val = (num1[i] - '0') * (num2[j] - '0');
                val = val + ans[i+j];   // add val with the carry so far

                int digit = val % 10;
                int carry = val / 10;

                ans[i+j] = digit;
                ans[i+j+1] = ans[i+j+1] + carry;
            }
        }

        // reverse 
        reverse(ans.begin(), ans.end());

        // remove leading zeroes
        int index = -1; // index where leading zeroes end
        for(int i = 0; i < ans.size(); i++) {

            if(ans[i] > 0) {
                break;
            }
            
            index++;
        }

        // convert int array to string
        string res = "";
        for(int num : ans) {
            res += "" + to_string(num);
        }

        // no leading zeroes
        if(index == -1) return res;

        return res.substr(index+1);
    }
};
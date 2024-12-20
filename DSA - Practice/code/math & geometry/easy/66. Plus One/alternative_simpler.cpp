class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        for (int i = n - 1; i >= 0; i--) {

            // if the digit is less than 9, simply add 1 and return    
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            // this means digit is 9, so we change it to 0 (assuming we added 1 and the result is now 10. As part of carry, we go to next iteration and add 1 to the next digit)
            digits[i] = 0;
        }

        // this means all digits were 9. So our result is 1xxxx where xxxx means the number of times there were 9 in input, that many times there will now be 0 in result
        vector<int> result(n + 1, 0);
        result[0] = 1;
        return result;
    }
};
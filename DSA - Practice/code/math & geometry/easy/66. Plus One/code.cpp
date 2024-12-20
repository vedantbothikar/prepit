/*

- https://leetcode.com/problems/plus-one/
- https://neetcode.io/solutions/plus-one

first reverse the array

add one to the 0th index, 
if carry, go to next index and continue same process

at last if carry is left, and you have reached end of the array, then push_back the carry

reverse the array

*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n = digits.size();
        deque<int> ans(n, 0);
        
        int carry = 0;
        int ind = n-1;

        while(ind >= 0) {

            int digit = digits[ind];

            if(ind == n-1) {
                digit += 1;
            }
            digit += carry;

            carry = digit / 10;
            digit = digit % 10;

            ans[ind] = digit;
            ind--;
        }

        // add carry to the end if carry is left
        while(carry != 0) {

            ans.push_front(carry);
            carry = carry / 10;
        }

        return vector<int> (ans.begin(), ans.end());
    }
};
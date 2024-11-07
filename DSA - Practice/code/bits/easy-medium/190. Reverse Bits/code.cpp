/*

- https://leetcode.com/problems/reverse-bits/
- https://leetcode.com/problems/reverse-bits/solutions/6021032/c-solution-in-o-1-time/

Approach:
Check the digits which are 1, one by one
    - Todo this, keep right shifting the number i times and check if the digit is 1

    - When you get this, add it to our res

i will loop from 0 to 31 (32 times)

-----

-> Step 1: check if the bit at that position is 1 (right shift n, i times and check last digit)
-> Step 2: put 1 in that position in the result


TC: 
SC: O(1)

*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        uint32_t res = 0; 
        for(int i = 0; i < 32; i++) {
            
            uint32_t bit = (n >> i) & 1;    // Step 1
            res = res + (bit << (31 - i));   // Step 2
        }

        return res;
    }
};
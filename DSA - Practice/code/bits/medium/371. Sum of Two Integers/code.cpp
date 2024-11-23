/*

- https://leetcode.com/problems/sum-of-two-integers/description/
- https://youtu.be/gVUrDV4tZfY?si=vNpDR3SUTj6BCB-D

a -> sum
b -> carry

Addition operation:
Step 1: sum can be found using XOR
Step 2: carry can be found using left shifting the result of AND (because it is carry)

Adding:
1001 (9)
1011 (11)

XOR: 0010
AND
AND: 1001
(left shifted): 10010

a = 0010
b = 10010

Now repeat the 2 steps for addition operation

XOR: 10000
AND (leftshifted): 000100

a = 10000
b = 000100

Now repeat the 2 steps for addition operation

XOR: 010100
AND (leftshifted): 000000

a = 010100
b = 000000

a -> answer

Complexity
Time complexity: O(1)
Space complexity: O(1)

*/

class Solution {
public:
    int getSum(int a, int b) {

        while(b != 0) {
            
            int temp = a;
            a = a ^ b;          // XOR
            b = (temp & b) << 1;   // AND with left shift
        }
        
        return a;
    }
};
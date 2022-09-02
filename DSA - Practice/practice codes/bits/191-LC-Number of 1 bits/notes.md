#Notes

**PROBLEM**

191. Number of 1 Bits

Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

https://leetcode.com/problems/number-of-1-bits/

Example 1:

Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.

---

**Approach**:

AND the number with `1`

loop until n !=0

If the ans is `1`:
=> count++

right shift `n`
so that you can check the next bit

**IMP**

To check if the last bit is set or not, `AND` it with `1`

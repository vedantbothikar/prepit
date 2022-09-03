#Notes

**Problem**:

1281. Subtract the Product and Sum of Digits of an Integer

https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

Given an integer number n, return the difference between the product of its digits and the sum of its digits.

Input: n = 234
Output: 15
Explanation:
Product of digits = 2 _ 3 _ 4 = 24
Sum of digits = 2 + 3 + 4 = 9
Result = 24 - 9 = 15

---

Whenever you want the last digit of a number
DO-
`n%10`

Remember these 2 things:

1. To check if last bit is set or not
   `n&1`

2. To get the last digit of a **decimal** number
   `n%10`

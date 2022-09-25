#Notes

**231. Power of Two**

https://leetcode.com/problems/power-of-two/

Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

---

**In `code.cpp`**

We are finding the number of 1s

If the number of 1s is greater than 1 then the number is not a power of 2

(I understood this by observation)

Eg:

1 -> 1 (2^0)
2 -> 10
4 -> 100
8 -> 1000
16 -> 10000

---

**In `code2.cpp`**

we are checking if the number is any one of the following one by one

2^0
2^1
.
.
.
2^29
2^30

_(int range is till 2^31-1 so we are checking only till 2^30)_

if the answer matches
then return true
else
return false

---

**In `code3.cpp`**

this is more efficient than using pow(2,i) (than code2.cpp)

because we are using the previous value of `val` and reducing the computation

---

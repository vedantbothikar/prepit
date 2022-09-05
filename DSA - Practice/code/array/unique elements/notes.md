#Notes

---

**BRUTE FORCE**

**code.cpp**

**O(n^2)**

2 3 6 3 6 1 2

for loop - from 0 to n-1

    => for loop check for all elements other than the current one
        if no duplicate then return true

---

**OPTIMIZED**

**O(n)**

**code2.cpp**

XOR every element

in XOR the duplicate elements will get _nulled_

Example:

2 ^ 3 ^ 1 ^ 6 ^ 3 ^ 6 ^ 2 = 1

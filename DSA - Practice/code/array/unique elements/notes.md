#Notes

https://www.codingninjas.com/codestudio/problems/find-unique_625159?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1

You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
You need to find and return that number which is unique in the array/list.

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

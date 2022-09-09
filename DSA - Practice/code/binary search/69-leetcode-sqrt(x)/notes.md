#Notes

**69. Sqrt(x)**

https://leetcode.com/problems/sqrtx/

---

`code3.cpp`

for explanation, you can watch:

https://youtu.be/6z2HK4o8qcU?t=2588

we are finding precision of the square root

initially factor = 0.1

then we are adding factor to the intSqrt and checking
if (intSqrt+factor)\*(intSqrt+factor)<n

which means, suppose n = 37
then intSqrt = 6
factor = 0.1

so check if 6.1\*6.1 <37

if yes

check if 6.2\*6.2 < 37

if yes

go ahead

if NO

then divide factor by 10
factor = 0.01

now check if 6.21\*6.21 < 37

if yes
check if 6.22\*6.22 < 37

and so on

---

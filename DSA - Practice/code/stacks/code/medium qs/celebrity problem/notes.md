#Notes

https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

---

Celebrity:

- Knows no one
- everyone know them

---

**Solution**:

- Stack
- Push all people in the stack (means -> 0 to n)
- While loop until there is only 1 element left in stack
- in every iteration:
  pop 2 elements a & b
  a knows b ? push b to stack : push a to stack

because if anyone of them know each other, they cannot be the celebrity

- so finally you will have just one element in the stack

**BUT WAIT, that is just a potential candidate:**

**So, now check if the `potcan`**

- knows no one
- everyone knows them

How to do this?

- knows no one
  means that the `row` corresponding to the `potcan` will have all **zeroes**

- everyone knows them
  means that the `column` corresponding to the `potcan` will have all **1s**
  (excpet `potcan`'s `row` (because that would mean `potcan` knows themselves, which is preposterous))

---

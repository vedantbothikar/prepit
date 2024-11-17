#Notes

https://www.codingninjas.com/codestudio/problems/delete-middle-element-from-stack_985246?leftPanelTab=0

---

`code.cpp`

Extra space

Solution:

You need to pop elements from stack till mid is at the top
(every time you pop, store it in a different stack as well)

Now pop mid

Now push other elements that were previously popped

---

`code2.cpp`

recursive approach

no extra space

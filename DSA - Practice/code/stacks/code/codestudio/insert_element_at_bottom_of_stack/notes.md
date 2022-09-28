#Notes

https://www.codingninjas.com/codestudio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

---

    // method 1:
    // use extra stack
    // pop elements from stack1 and put in stack2 until empty
    // insert the new element
    // push all elements from stack2 to stack1
    // Space complexity: O(N)
    // Time complexity: O(N)

    // method 2:
    // we need to reduce space used
    // so let's try recursion
    // base case when stack is empty
    // base case hit: insert the new element
    // basic step is to pop the element
    // then recursive call
    // then push the element

---

**By doing it recursively, you are saving extra space**

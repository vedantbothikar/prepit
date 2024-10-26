/*



- https://www.geeksforgeeks.org/convert-bst-min-heap/

Solution: Watch video from here:
- https://youtu.be/_9F2VgZcvdw?si=a37oZXkFdZzQXMLn&t=3355



*/

/*

Logic:

In a MinHeap:
- root < right
- root < left

And additional condition they have given is:
left subtree values is less than right, this means for all elements
left < right

Combining both of these conditions means:

root < left < right

On observation, this is the condition for preorder traversal

So it means we need to give the preorder traversal


*/

/*
Some notes from chatgpt:
The reason we need to **perform an inorder traversal** first and then **convert the tree using preorder traversal** is to ensure that the resulting **Min Heap** maintains the required **heap property**:

### Why Inorder Traversal First?

1. **Inorder Traversal of a BST Gives a Sorted Array**:
   - When you perform **inorder traversal** on a **Binary Search Tree (BST)**, you get the elements in **sorted order** (ascending).
   - This is important because to build a **Min Heap**, we need to ensure that:
     - The **root node** has the **smallest value** among all the nodes.
     - The **left child** is less than or equal to the **right child**, and so on.
   
2. **Min Heap Requires Elements in Ascending Order**:
   - In a **Min Heap**, the **smallest element** should be at the **root**, and all children should be **greater** than or equal to their parent node.
   - By **storing the BST elements in a sorted array**, we can guarantee that when we start placing them in **preorder**, we are putting **smaller elements first**, which helps in maintaining the **Min Heap property**.

### Why Not Just Use Preorder of the BST Directly?

If you were to simply print or convert the **preorder traversal of the BST**, it would **not necessarily** form a **Min Heap**. Here’s why:

1. **BST and Min Heap Properties Differ**:
   - In a **BST**, the left child can have any value as long as it is **less than** the root, and the right child can have any value **greater than** the root.
   - However, in a **Min Heap**, the left child must be **greater than or equal** to the root, and the right child must also be **greater than or equal** to the root. This is a very different structure.
   
2. **Preorder Traversal Won't Reorder Elements Correctly**:
   - Simply performing a **preorder traversal** of the **BST** will **not** rearrange the elements correctly to meet the **Min Heap** requirements.
   - The resulting tree may **not** satisfy the Min Heap condition where **all nodes** must be **greater than** their **parent nodes**.

### Conversion Process Summary:

1. **Perform Inorder Traversal**:
   - Gather all elements of the BST in a **sorted array**.
   - This ensures the **smallest elements** come first.

2. **Modify the Tree Using Preorder Traversal**:
   - When you perform **preorder traversal** to modify the tree, you start at the **root**.
   - Replace the root with the **smallest element** from the sorted array.
   - Proceed down the tree, **placing the smallest available elements first**, which results in a valid **Min Heap**.

### Example to Illustrate:

Suppose you have a **BST**:
```
       4
     /   \
    2     6
   / \   / \
  1   3 5   7
```

1. **Inorder Traversal**: `{1, 2, 3, 4, 5, 6, 7}` (sorted order)
2. **Preorder Traversal to Convert**:
   - Start placing the **sorted elements** from the **array** into the **tree**:
   - Root becomes **1**, then left child **2**, right child **3**, and so on.

### Resulting Min Heap:
```
       1
     /   \
    2     3
   / \   / \
  4   5 6   7
```

### Conclusion:

- **Inorder traversal** ensures that we have **elements in ascending order**.
- Using **preorder traversal** to place these elements helps create a **Min Heap** where **every node** has **smaller or equal children**.
- Simply using the **preorder of the original BST** would **not** guarantee a valid **Min Heap** structure.

*/
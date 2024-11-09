#Notes

https://leetcode.com/problems/subsets/

---

For explanation check:
[Babbar DSA Lecture 37](https://youtu.be/V0IgCltYgg4)

---

This code studio problem is same as 78-leetcode

Just the difference is that we are using strings here

https://www.codingninjas.com/codestudio/problems/subsequences-of-string_985087?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_16

---

Here we have choices:
First choice is to select the character
Second choice is to NOT select the character

for excluding the character
=> we just go to the next index

for including the character
=> we first add the character in the `output`
=> then go to the next index

You will add the `output` to `ans` only when index reaches at the end
(this is because, our answers are at the leaves of the recursion tree)

---

Recursion tree

Note: Our answer is in the leaves of the tree

[View in browser](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/f3fb70a6-684b-426e-be02-d28a3f0e4683/tree.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20220917%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20220917T172050Z&X-Amz-Expires=86400&X-Amz-Signature=fe9c4dc0df9a232ba9a21e21c6a1a1671657ec3160b16fe87eea2473887cafde&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D"tree.png"&x-id=GetObject)

![](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/f3fb70a6-684b-426e-be02-d28a3f0e4683/tree.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20220917%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20220917T172050Z&X-Amz-Expires=86400&X-Amz-Signature=fe9c4dc0df9a232ba9a21e21c6a1a1671657ec3160b16fe87eea2473887cafde&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D"tree.png"&x-id=GetObject)

---

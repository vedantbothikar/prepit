/*

- https://leetcode.com/problems/add-two-numbers/
- https://neetcode.io/solutions/add-two-numbers

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*

Solution: (Watch video)
- https://neetcode.io/solutions/add-two-numbers

since we have to add two numbers
we can simply iterate through both the linkedlists at the same time and the two digits.

Note:
we have to traverse in the forward direction only because it is already given that the numbers are in reverse order in the linkedlist. And whenever we normally add 2 numbers we always start with the end (reverse order). So, that means we are all good in terms of direction.


The only thing we need to consider is 
1. that if l1 and l2 are of different lengths
2. When carry is left even after adding both numbers

1] ->
If they are of different lengths, if the node of any linkedlist becomes null, we should assume that there is 0 at that position and keep adding the digits of the other linkedlist


2] ->
We should also loop until the carry is 0. Because we want our carry as well to be added to the number

Note:
Since we have to return a linkedlist as answer, we will create nodes of the sum and keep addin to the resulting linkedlist


TC: O(n)
SC: O(1)

*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dummy = new ListNode();
        ListNode* ans = dummy;

        int carry = 0;
        // NOTE: the conditions are OR and not AND (while any of them is true, you have to loop and keep adding)
        while(l1 != nullptr or l2 != nullptr or carry != 0) {

            // computer num1 and num2
            int num1 = (l1 == nullptr) ? 0 : l1->val;
            int num2 = (l2 == nullptr) ? 0 : l2->val;

            // compute new sum and carry
            int temp = num1 + num2 + carry;

            carry = temp / 10;
            int sum = temp % 10;

            // create next node
            ans->next = new ListNode(sum);
            ans = ans->next;

            // increment pointers
            l1 = (l1 == nullptr) ? nullptr : l1->next;
            l2 = (l2 == nullptr) ? nullptr : l2->next;
        }

        return dummy->next;
    }
};
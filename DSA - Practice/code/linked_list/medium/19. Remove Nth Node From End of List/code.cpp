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

- https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
- https://neetcode.io/solutions/remove-nth-node-from-end-of-list

Of course we can solve it in a two pass algorithm where we first find the lenght of the linked list and then do some calculations and then delete the node.

But to solve it in a single pass:
Keep 2 pointers, left and right

- Advance right by n steps
- Now start the left pointer and advance it until right->next reaches nullptr

This will bring the left pointer to a node before the node that is to be removed. Now remove the node next to the left pointer.

TC: O(N)
SC: O(1)

*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* left = head;
        ListNode* right = head;
        // advance right n steps
        while(n > 0) {

            right = right->next;
            n--;
        }   

        // edge case: when right has already reached the end (nullptr)
        // this means n was equal to the size of the list,
        // this means we have to essentially remove the head
        if(right == nullptr) {
            
            head = head->next;
            return head;
        }

        // now start advancing the left pointer: until we reach node just before the node to be deleted
        while(right->next != nullptr) {

            left = left->next;
            right = right->next;
        } 

        // remove the node
        left->next = left->next->next;

        return head;
    }
};
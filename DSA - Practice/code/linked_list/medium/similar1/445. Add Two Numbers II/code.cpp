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

- reverse the linked list, then add the 2 numbers as you would do in this problem: 
https://leetcode.com/problems/add-two-numbers/description/?envType=study-plan-v2&envId=programming-skills

*/
class Solution {

    ListNode* reverseList(ListNode* l) {

        /*
            - break the first node
            - from the second node - use a while loop
                - break the node and attach to prev node
        */

        // base condition
        if(l == nullptr) return nullptr;

        // break first node
        ListNode* prevNode = l;
        l = l->next;    // goto second node
        prevNode->next = nullptr;

        while(l != nullptr) {

            ListNode* currNode = l;

            l = l->next;    // go to next node
            currNode->next = prevNode;  // break link

            prevNode = currNode;    // prepare for next iteration
        }

        return prevNode;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        int prevCarry = 0;
        ListNode* ans = new ListNode();
        ListNode* temp = ans;

        while(l1 != nullptr or l2 != nullptr or prevCarry != 0) {

            // get both nums
            int num1 = (l1 == nullptr) ? 0 : l1->val;
            int num2 = (l2 == nullptr) ? 0 : l2->val;

            // perform addition
            int sum = num1 + num2 + prevCarry;
            int carry = sum / 10;
            int digit = sum % 10;

            // create and attach the new node
            ListNode* newNode = new ListNode();
            newNode->val = digit;
            temp->next = newNode;
            temp = temp->next;

            // prepare for next iteration
            prevCarry = carry;
            l1 = (l1 == nullptr) ? nullptr : l1->next;
            l2 = (l2 == nullptr) ? nullptr : l2->next;
        }

        return reverseList(ans->next);
    }
};
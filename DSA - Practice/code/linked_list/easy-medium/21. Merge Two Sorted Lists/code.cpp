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

- https://leetcode.com/problems/merge-two-sorted-lists/

*/

class Solution {

    ListNode* solve(ListNode* head1, ListNode* head2) {

        ListNode* start = new ListNode(0);
        ListNode* current = start;  // use current to traverse the list

        while(head1 != NULL and head2 != NULL) {

            if(head1->val < head2->val) {

                current->next = new ListNode(head1->val);
                head1 = head1->next;
            }
            else if(head2->val < head1->val) {
                
                current->next = new ListNode(head2->val);
                head2 = head2->next;
            }
            else {  // this means both values are equal

                current->next = new ListNode(head1->val);
                head1 = head1->next;

                current = current->next;

                current->next = new ListNode(head2->val);
                head2 = head2->next;
            }

            current = current->next;
        }

        // merge all remaining nodes
        while(head1 != NULL) {

            current->next = new ListNode(head1->val);
            
            head1 = head1->next;
            current = current->next;
        }

        while(head2 != NULL) {

            current->next = new ListNode(head2->val);
            
            head2 = head2->next;
            current = current->next;
        }

        return start->next;
    }

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        return solve(list1, list2);
    }
};
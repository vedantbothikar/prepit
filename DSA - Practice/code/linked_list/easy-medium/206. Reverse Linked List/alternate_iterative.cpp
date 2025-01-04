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

iteratively:
keep a Node prev = new node

traverse the list, disconnect and connect its next to prev
keep doing this


at the end remove the last node


*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        // base case
        if(head == NULL) return head;

        ListNode* temp = head;

        // disconnect the first node and make its next as NULL
        // since this first node will become the last node on reversing
        ListNode* prev = temp;
        temp = temp->next;
        prev->next = NULL;

        while(temp != NULL) {

            // disconnect the node and connect to prev
            ListNode* x = temp->next;
            
            temp->next = prev;
            prev = temp;

            temp = x;
        }

        return prev;
    }
};
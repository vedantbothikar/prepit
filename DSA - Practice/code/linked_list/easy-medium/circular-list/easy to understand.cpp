/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*

- https://leetcode.com/problems/linked-list-cycle/description/

Approach
Ff cycle is present, the slow and fast pointers will reach at a point.
If cycle not present, fast will reach NULL at some point.

Complexity
Time complexity: O(N)
Space complexity: O(1)


*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        // base condition
        if(head == NULL) return false;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL) {

            // loop condition
            if(slow == fast) return true;

            slow = slow->next;

            fast = fast->next;
            if(fast == NULL) return false;
            fast = fast->next;
        }

        return false;
    }
};
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

- https://leetcode.com/problems/reorder-list/description/


# Approach
To solve it without additional space, we can 

- first reverse the second half of the list 
    - this is so that we can get the nodes from second half in reverse order

- then we can merge the first and second halves in the fashion asked in qs


How to reverse a list:
- first find the middle position (using slow and fast ptrs)
- then reverse the list starting from mid->next

# Complexity
- Time complexity: O(n)

- Space complexity: O(1)

*/

class Solution {

    ListNode* midPos(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next) {
            
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverseSecondHalf(ListNode* curr) {

        ListNode* prev = nullptr;

        while(curr) {

            ListNode* temp = curr->next;

            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }

public:
    void reorderList(ListNode* head) {
        
        // Step 1: find the mid position
        ListNode* mid = midPos(head);

        // disconect first and second halves 
        ListNode* secondListStart = mid->next;
        mid->next = nullptr;

        // Step 2: reverse the second half of the list
        ListNode* second = reverseSecondHalf(secondListStart);

        ListNode* first = head;
        // merge both lists as required
        while(second != nullptr) {

            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};
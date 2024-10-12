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

recursively solve this
go to last node recursively while keep a track of the previous node
then on reaching last node, reverse

TC: O(N)
SC: O(N)    // recursive stack space

*/

class Solution {

    void solve(ListNode* head, ListNode* prev, ListNode*& start) {

        // base case: when we reach last node
        if(head == NULL) {
            start = prev;
            return;
        }

        // recurse
        solve(head->next, head, start);

        // reverse
        head->next = prev;
    }

public:
    ListNode* reverseList(ListNode* head) {

        ListNode* start = NULL;
        solve(head, NULL, start);
        return start;
    }
};
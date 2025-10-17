/*

Problem Link: https://leetcode.com/problems/reverse-nodes-in-k-group/description/

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


#### 
- keep a dummy head pointer
- reverse in groups

- maintain the groupPrev and groupNext and kth node


#### 
- function to check if there are k nodes in the group, if yes, return the kth node

#### 
reversing in group of k:

Intiial:
groupPrev -> 1st node -> 2nd node -> . . . -> kth node -> groupNext

Expected:
groupPrev -> kth node -> . . . -> 2nd node -> 1st node -> groupNext

---------

BUT, A normal reverse linkedlist would do this:
groupPrev <--> 1st node <- 2nd node <- ... kth node           groupNext ...


firstNode = curr
curr = groupPrev->next
prev = groupNext    // because we want the 1st node to point to groupNext
1stNode = groupPrev->next

for k times:
    Node* temp = curr->next
    curr->next = prev
    prev = curr
    curr = temp


groupPrev->next = kthNode

// for next iteration
groupPrev = 1stNode


*/
class Solution {

    ListNode* getKthNode(ListNode* node, int k) {

        while(node and k > 0) {
            node = node->next;
            k--;
        }

        return node;
    }


public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* initHead = new ListNode(0, head);    // a node before the start for ease

        ListNode* groupPrev = initHead;

        while(true) {

            ListNode* kthNode = getKthNode(groupPrev, k);
            if(kthNode == nullptr) break;   
            
            // reverse in groups of k
            ListNode* groupNext = kthNode->next;
            ListNode* firstNode = groupPrev->next;
            
            ListNode* curr = groupPrev->next;
            ListNode* prev = groupNext; // this is important: reason: check comments above

            for(int i = 0; i < k; i++) {
                
                // normal reverse linked list
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // adjust the groupPrev
            groupPrev->next = kthNode;

            // prepare for next iteration
            groupPrev = firstNode;
        }

        return initHead->next;
    }
};
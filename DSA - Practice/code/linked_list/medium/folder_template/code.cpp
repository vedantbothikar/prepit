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

92. Reverse Linked List II
- https://leetcode.com/problems/reverse-linked-list-ii/description/


l1: the node on left block just before the part to be reversed
l2: the node on right block just after the part to be reversed

traverse the ll
    - note to keep track of prevNode
as soon as you find the leftnode
    - reversell(leftnode, (right-left+1))
    return rightNode

// note: check if l1 and l2 are not null
l1->next = rightnode;
l2 = rightnode->next
leftnode->next = l2

reverseall(leftnode, dist, prevNode = nullptr):
    // base case
    if dist == 1: return leftnode;

    for dist no. of times:
        Node* temp = curr->next;
        curr->next = prevNode;
        prev = curr
        curr = temp

    return {prev, curr} // {right, l2}



NOTE: There is a simpler logic solution as well: check youtube videos

*/
class Solution {

    pair<ListNode*, ListNode*> reversell(ListNode* curr, int dist) {

        // base case: 
        if(dist == 1) return {curr, curr->next};

        ListNode* prev = nullptr;
        for(int i = 0; i < dist; i++) {

            // reverse logic
            ListNode* temp = curr->next;
            curr->next = prev;

            prev = curr;
            curr = temp;
        }

        return {prev, curr};    // {right, l2}
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* l1 = nullptr;
        ListNode* ogHead = head;
        ListNode* leftNode = head;

        // traverse till you reach left node
        for(int i = 1; i < left; i++) {
            l1 = leftNode;
            leftNode = leftNode->next;
        }

        // now we have reached the leftnode: reversell
        pair<ListNode*, ListNode*> p = reversell(leftNode, right - left + 1);
        auto [rightNode, l2] = p;

        if(l1) {
            l1->next = rightNode;
        }
        leftNode->next = l2;

        if(l1 == nullptr) return rightNode;

        return ogHead;
    }
};
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

- https://leetcode.com/problems/merge-two-sorted-lists/description/?envType=study-plan-v2&envId=programming-skills

Node* ans = new Node
Node* temp = ans

2 pointers

do this until both p1 and p2 are not NULL
if p1 < p2:
    temp->next = p1
    // disconnect p1 and move ahead

whichever of p1 or p2 is not NULL, attach it to temp


*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* ans = new ListNode();
        ListNode* temp = ans;

        while(list1 != NULL && list2 != NULL) {

            if(list1->val < list2->val) {
                
                // attach to temp and move temp ahead 
                temp->next = list1;
                temp = temp->next;

                // disconnect current list1 node
                list1 = list1->next;

                temp->next = NULL;
            }
            else {

                // attach to temp and move temp ahead 
                temp->next = list2;
                temp = temp->next;

                // disconnect current list1 node
                list2 = list2->next;   

                temp->next = NULL;             
            }
        }

        // attach list which is non null
        if(list1 != NULL) {
            temp->next = list1;
        }
        if(list2 != NULL) {
            temp->next = list2;
        }

        return ans->next;
    }
};
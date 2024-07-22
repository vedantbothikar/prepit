

/*

PROBLEM: https://leetcode.com/problems/merge-two-sorted-lists/

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
COMMENTS:
- Check if we can do it in constance space?

APPROACH:

traverse both lists together
We will take any one list of them, 
access the elements one by one,
- compare it with element of the other list,
- choose the smallest one amongst them and attach it to the result list
- increment the pointer of the list of which element has been chosen

- Now when we reach the end of any one list, then break the loop
- Now loop in another list and attach all element of that list to the result and return it


*/


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode finalRes(0);
        ListNode *res = &finalRes;

        while(list1 != nullptr && list2 != nullptr) {

            if(list1->val < list2->val) {
                
                res->next = list1;
                list1 = list1->next;
            }
            else {

                res->next = list2;
                list2 = list2->next;
            }

            res = res->next;
        }

        while(list1 != nullptr) {
            
            res->next = list1;
            res = res->next;
            list1 = list1->next;
        }

        while(list2 != nullptr) {

            res->next = list2;
            res = res->next;
            list2 = list2->next;
        }

        return finalRes.next;
    }
};
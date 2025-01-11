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

This approach is if you want to avoid reversing the list. This can be done using stacks.

Add all elements in both stacks and start accessing elements from the top of the stack which will give you the elements in the reverse order

*/
class Solution {

    void pushToStack(stack<int>& s, ListNode* l) {

        while(l != nullptr) {
            s.push(l->val);
            l = l->next;
        }
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        stack<int> s1, s2;

        // push elements in stack
        pushToStack(s1, l1);
        pushToStack(s2, l2);

        // perform addition

        int prevCarry = 0;
        ListNode* ans = nullptr;

        while(!s1.empty() or !s2.empty() or prevCarry != 0) {

            // get both numbers
            int num1 = 0, num2 = 0;
            if(s1.empty() == false) {
                num1 = s1.top();
                s1.pop();
            }

            if(s2.empty() == false) {
                num2 = s2.top();
                s2.pop();
            }

            // perform addition
            int sum = num1 + num2 + prevCarry;
            int digit = sum % 10;
            int currCarry = sum / 10;

            // attach digit to ans list (in reverse order)
            // becase ans is expected in reverse order
            ListNode* newNode = new ListNode(digit);
            newNode->next = ans;
            ans = newNode;

            // prepare for next iteration
            prevCarry = currCarry;
        }

        return ans;
    }
};
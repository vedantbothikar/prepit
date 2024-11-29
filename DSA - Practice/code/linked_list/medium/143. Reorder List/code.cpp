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

I can use a queue:
- push all nodes into the queue

continue process

Complexity
Time complexity: O(n)
Space complexity: O(n)


*/
class Solution {

    void pushNodesToDq(ListNode* head, deque<ListNode*>& dq) {

        ListNode* temp = head;

        while(temp != nullptr) {
            
            cout << "Pushing: " << temp->val << endl;
            dq.push_back(temp);
            temp = temp->next;
        }
    }

public:
    void reorderList(ListNode* head) {
        
        deque<ListNode*> dq;
        // push all nodes to queue
        pushNodesToDq(head, dq);

        ListNode* temp = head;

        // pop first node since we already have first node in temp pointer
        ListNode* firstNode = dq.front();
        cout << "firstNode: " << firstNode->val << endl;
        dq.pop_front();

        while(!dq.empty()) {

            // Step 1: join back node
            // back node
            ListNode* backNode = dq.back();
            cout << "backNode: " << backNode->val << endl;
            dq.pop_back();

            // join back node
            temp->next = backNode;
            temp = temp->next;

            // Step 2: join next front node
            if(!dq.empty()) {

                // join next front node
                ListNode* dqStart = dq.front();
                dq.pop_front();

                cout << "dqStart: " << dqStart->val << endl;

                temp->next = dqStart;
                temp = temp->next;
            }
        }

        // The reordering logic does not explicitly terminate the reordered list. After all nodes are processed, the last node's next pointer will still point to its original next node, creating a cycle or incorrect linkage.
        temp->next = nullptr;
    }   
};
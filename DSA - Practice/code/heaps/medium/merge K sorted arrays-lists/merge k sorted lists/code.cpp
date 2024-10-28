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

class customComp {

public:
    bool operator()(ListNode* a, ListNode* b) {

        return a->val > b->val;
    }

};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        vector<ListNode*> tempLists = lists;
        ListNode* ans = new ListNode(0);
        ListNode* tempAns = ans;
        priority_queue<ListNode*, vector<ListNode*>, customComp> pq;    // min heap

        int k = lists.size();
        // push k elements in the pq (first elements of all lists)
        for(ListNode* listPtr : lists) {
            if(listPtr){
                pq.push(listPtr);  // we are pushing the ListNode* in the pq
            }
        }

        // until the pq is empty, put the min value to ans and push a new value to pq
        while(!pq.empty()) {

            // put top element in ans
            ListNode* minElement = pq.top();
            tempAns->next = minElement;
            tempAns = tempAns->next;
            pq.pop();

            ListNode* nextNode = minElement->next;
            if(nextNode != nullptr) {
                pq.push(nextNode);
            }
        }

        return ans->next;
    }
};
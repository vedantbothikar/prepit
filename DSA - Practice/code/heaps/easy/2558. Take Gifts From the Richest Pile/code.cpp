/*

- https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/

- Take max element
- Take x from that. (Meaning change the value to something else)

Max heap:
- put all elements in the heap
O(nlogn)


- Pop max element
- Change value (do operations)
- Push the new value
O(k*logn)

Do this k times.
- push O(logn)
- pop(logn)


TC: O(nlogn + klogn)
SC: O(n)

*/

using ll = long long;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {

        priority_queue<int> maxheap;
        ll totalSum = 0;

        // populate in maxheap
        for(int gift : gifts) {

            maxheap.push(gift);
            totalSum += gift;
        }
        
        ll totalTaken = 0;
        // perform operations for k seconds
        for(int i = 0; i < k; i++) {

            // pop the max element
            int maxEle = maxheap.top();
            maxheap.pop();

            // leave behind some gifts
            int leftGift = floor(sqrt(maxEle));
            totalTaken += maxEle - leftGift;

            // push the leftGift to maxheap
            maxheap.push(leftGift);
        }

        return totalSum - totalTaken;
    }
};
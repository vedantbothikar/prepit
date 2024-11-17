/*

- https://leetcode.com/problems/last-stone-weight/description/


Brute:
- While there is one element left in the array, 
- find the max, then remove the element,
- then find the max again, then remove that element
- put the result back in the array

Better:
- sort the array
- get the last number, then pop it
- get the new last number, then pop it again
- put the result of subtraction in the array back
- keep doing until there is one element
    - but when we put back the element we need to sort again, so this will take lot of time

Alternative:
- If I use make_heap method to put all elements from vector to maxheap O(N)
- then take out elements from the heap one by one and do the operations
    - popping will take O(logN)
    - pushing will take O(logN)
TC: O(NlogN)

*/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        // create maxheap
        priority_queue<int> pq;
        for(int stone : stones) {
            pq.push(stone);
        }

        while(pq.size() > 1) {

            // first max
            int max1 = pq.top();
            pq.pop();

            int max2 = pq.top();
            pq.pop();

            if(max1 == max2) {
                
                cout << "pqtop: " << pq.top() << endl;
                if(pq.size() == 0) return 0;
                else continue;
            }
            pq.push(abs(max1 - max2));
        }

        return pq.top();
    }
};
/*

- https://leetcode.com/problems/kth-largest-element-in-an-array/

Solution: Look at Q1 in this video
https://youtu.be/_9F2VgZcvdw?si=2dbuEA05hWHsBA2C

TC: O(n∗logk)
SC: O(k)

*/

/*

Let use min heap
- Push first k elements in the minheap
- For rest other elements, check if they are greater than the top of the minheap
- If they are greater, then:
    - pop the top from the heap
    - push new element to the heap
<till here essentially what we have done is pushed the top k greatest elements in the min heap>
<this means that the smallest element in the top k greatest elements will be the kth greatest element>
- So, Now finally, return the top of the minheap, this will be the Kth largest element in the array


*/


class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        
        priority_queue<int, vector<int>, greater<int>> minheap;

        // push first k elements in the min heap
        for(int i = 0; i < k; i++) {
            minheap.push(arr[i]);
        }

        // compare rest all elements with the top of the minheap
        for(int i = k; i < arr.size(); i++) {
            
            // check if the element is greater than the top of the minheap
            if(arr[i] > minheap.top()) {

                minheap.pop();
                minheap.push(arr[i]);
            }
        }

        return minheap.top();
    }
};
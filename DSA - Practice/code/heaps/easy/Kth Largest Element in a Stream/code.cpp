/*
- https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
- 

*/


/*

Time complexity:
Constructor: O(nlogk)
add: O(logk)
Space complexity: O(n)

we can maintain a heap of top k largest elements
This will be a min-heap of top k largest elements
And our answer will be the root of the minheap

# HOW DO WE CREATE A MIN HEAP OF K LARGEST ELEMENTS?
- Put the first k elements in the min heap
- for the rest n-k elements, compare if the element is greater than the smallest of the min heap (smallest of min heap will be the top of the min heap)
    - if any of the n-k elements is greater than the top of the min heap, then you can pop the top of minheap and insert the new element in the minheap
    - else if any of the n-k elements is smaller, then ignore and try other elements

Now that you have the min heap of the k largest elements in the heap,
Whenever we have a new element we will again follow the same conditions as we did earlier 
    - if element greater than the min, then insert in the minheap
    - else ignore


*/

#include<bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int> > pq;
    KthLargest(int k, vector<int>& nums) {
        
        this->k = k;

        for(int num : nums) {
            pq.push(num);
            if(pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k) pq.pop();

        return pq.top();
    }
};

int main() {

    vector<int> nums = {4, 5, 8, 2};
    KthLargest k(3, nums);

    cout << k.add(3) << endl;
    cout << k.add(5) << endl;
    cout << k.add(10) << endl;
    cout << k.add(9) << endl;
    cout << k.add(4) << endl;


    cout << "Hello World2!" << endl;
    cout << "Hello World2!" << endl;

    return 0;
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
/*

- https://leetcode.com/problems/pancake-sorting/

So we will first find the largest element and place it at the end

How to find largest element?
- use in built function or custom logic

How to place the element at end?
Suppose we have 
1,5,4,3,2
we find the index of largest element index = 2 (1 based indexing)

Step 1: reverse first index = 2 elements
5 1 4 3 2
Now reverse all elements
2 3 4 1 5

Now 5 is at correct position.
Now solve for array of length 0 to n-2
and so on...


*/
class Solution {

    void flip(vector<int>& arr, int k) {

        reverse(arr.begin(), arr.begin() + k);
    }

public:
    vector<int> pancakeSort(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> ans;

        for(int i = n-1; i >= 0; i--) {

            auto it = max_element(arr.begin(), arr.begin() + i+1);  // ending element should be greater than till where you want to sort

            int index = it - arr.begin();
            
            ans.push_back(index+1);
            flip(arr, index+1);

            ans.push_back(i+1);
            flip(arr, i+1);
        }

        return ans;
    }
};
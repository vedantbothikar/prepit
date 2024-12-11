/*

- https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/description/?envType=company&envId=salesforce&favoriteSlug=salesforce-three-months&status=SOLVED

Read detailed solution:
(copy of leetcode editorial) 
- https://gist.github.com/vedantbothikar/458a8e5b47ce7bc0e1d5aa1d285a3300


We can use a stack,

As long as the values are in decreasing order, we are fine with it.
But when a value is greater than the top of the stack, then we need to keep popping until a value greater appears

And the previous smaller value, inside this subtreee we will assume to insert the new node in the right side, since it is greater

minLimit is that exactly. It represents the min value the new value must be

TC: O(n)
SC: O(n)

*/
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {

        int minLimit = INT_MIN;
        stack<int> s;

        for(int num : preorder) {

            while(!s.empty() && s.top() < num) {
                minLimit = s.top();
                s.pop();
            }

            if(num <= minLimit) {
                return false;
            }

            s.push(num);
        }
        
        return true;
    }
};
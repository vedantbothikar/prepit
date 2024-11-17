/*
- https://leetcode.com/problems/validate-binary-search-tree/description/
- https://youtu.be/s6ATEkipzow

*/

/*

Approach
Simply checking if the element on right is greater and element on left is smaller than root, is not going to help. The reason is that we also need to check if the nodes at bottom are also in bounds with the nodes 2 or more levels above.

So we will keep a range checker for that

lowestValid = INT_MIN
highestValid = INT_MAX

As we go right the elements MUST be greater than the updated lowestValid

updated lowestValid will be equal to the current node when we go right
As we go left the elements MUST be smaller than the updated highestValid

updated highestValid will be equal to the current node when we go left

Complexity
Time complexity: O(n)
Space complexity: O(n)

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    bool dfs(TreeNode* root, long lowestValid, long highestValid) {

        // base conditions
        if(root == NULL) return true;

        if(root->val <= lowestValid or root->val >= highestValid) return false;
        
        // logic: check if left and right subtrees are also valid
        bool left = dfs(root->left, lowestValid, root->val);
        bool right = dfs(root->right, root->val, highestValid);

        return left && right;
    }

public:
    bool isValidBST(TreeNode* root) {

        return dfs(root, LONG_MIN, LONG_MAX);
    }
};
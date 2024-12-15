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
/*
So, the thing is that I have to add the sum of all nodes on the right of any node to the current node and I will get the Greater tree.

So, to add the sum of all nodes on the right, what if I traverse the bst in inorder way but actually in a a reverse inorder way?
That means, go right first, then visit current node, then go left

rev_inorder(root->right)

currentSum += root->val // update the running total sum
root->val = currentSum  // update the current node value

rev_inorder(root->left)


Complexity
Time complexity: O(n)

Space complexity: O(n) // recursive call stack
// worst case the tree could be skewed


*/
class Solution {

    void rev_inorder(TreeNode* root, int& currSum) {

        // base case
        if(root == nullptr) return;

        rev_inorder(root->right, currSum);

        currSum += root->val; // update the running total sum
        root->val = currSum;  // update the current node value

        rev_inorder(root->left, currSum);
    }

public:
    TreeNode* convertBST(TreeNode* root) {

        // edge case:
        if (root == nullptr) {
            return root;
        }

        int currSum = 0;
        rev_inorder(root, currSum);

        return root;
    }
};
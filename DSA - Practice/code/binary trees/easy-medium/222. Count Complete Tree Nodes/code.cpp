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

Problem Link: https://leetcode.com/problems/count-complete-tree-nodes/
Problem Number: 222



Watch: https://www.youtube.com/watch?v=u-yWemKGWO0

Brute force: solve using inorder traversal (O(N) time) 

Optimized approach:
We should take benefit of the fact that it is a complete binary tree

Note that if it is a perfect binary tree, the number of nodes are 
2^height - 1

So for the subtrees that are perfect binary trees
we can directly calculate the number of nodes and dont need to perform the traversal ahead.
How to check if the subtree at a node is perfect binary tree?
LeftHeight, RightHeight
LeftHeight: Keep going left until nullptr. Calc the height
RightHeight: Keep going right until nullptr. Calc the height

If the LeftHeight and RightHeight are EQUAL:
- then it is a perfect binary tree since it is fully populated and same depth on both sides



NOW,
for those subtrees that are NOT perfect binary trees
we can continue the traversal.
So for these we can do

count = 1 + solve(left) + solve(right)



TC: O((logN)^2)
    -> logN for the height traversal
    -> another logN since we are not doing the entire dfs for all nodes
        (we are shortcutting by doing the math to calculate total nodes)
SC: O(logN)


*/
class Solution {

    int getLeftHeight(TreeNode* root) {

        int height = 0;
        while(root) {
            height++;
            root = root->left;
        }

        return height;
    }

    int getRightHeight(TreeNode* root) {

        int height = 0;
        while(root) {
            height++;
            root = root->right;
        }

        return height;       
    }

    int countNodesInTree(TreeNode* root) {

        // base case: node is null
        if(root == nullptr) return 0;

        // check if it is a perfect binary tree
        int leftHeight = getLeftHeight(root);
        int rightHeight = getRightHeight(root);
        if(leftHeight == rightHeight) {
            return pow(2, leftHeight) - 1;
        }
        
        // in case it is NOT a pefect binary tree
        // go down and check 
        // add 1 for the count of the current node
        return 1 + countNodesInTree(root->left) + countNodesInTree(root->right);
    }


public:
    int countNodes(TreeNode* root) {
        
        return countNodesInTree(root);
    }
}; 
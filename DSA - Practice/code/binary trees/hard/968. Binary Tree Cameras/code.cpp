/*

LeetCode 968: Binary Tree Cameras
Problem Link: https://leetcode.com/problems/binary-tree-cameras/description/

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
/*




########################################################################
GREEDY Solution:

We start from bottom and then come up.

ALL YOU NEED TO UNDERSTAND:
If the node's children are covered, and it has a parent, then it is strictly better to place the camera at the parent.



This means that:
- If any of the children are not covered or
- If the node doesn't have a parent and is not covered

    => Place the camera at the current position.


########################################################################


LEETCODE WORDS EXPLANATION:
Intuition
Instead of trying to cover every node from the top down, let's try to cover it from the bottom up - considering placing a camera with the deepest nodes first, and working our way up the tree.

If a node has its children covered and has a parent, then it is strictly better to place the camera at this node's parent.

Algorithm
If a node has children that are not covered by a camera, then we must place a camera here. Additionally, if a node has no parent and it is not covered, we must place a camera here.


Time Complexity: O(N), where N is the number of nodes in the given tree.

Space Complexity: O(H), where H is the height of the given tree.


*/
class Solution {

    void dfs(TreeNode* node, TreeNode* parent, unordered_set<TreeNode*>& covered, int& camCount) {

        // base case
        if(node == nullptr) return;

        // goto bottom of dfs
        dfs(node->left, node, covered, camCount);
        dfs(node->right, node, covered, camCount);


        // check if we need to add a camera here
        // condition1: left node is not covered
        // condition2: right node is not covered
        // condition3: parent is null and current node is not covered
        bool condition1 = (covered.find(node->left) == covered.end());
        bool condition2 = (covered.find(node->right) == covered.end());
        bool condition3 = (parent == nullptr and covered.find(node) == covered.end());

        if(condition1 or condition2 or condition3) {

            // add a camera here
            camCount++;
            
            // cover the current node, parent, and children
            covered.insert(node);
            covered.insert(parent);
            covered.insert(node->left);
            covered.insert(node->right);
        }
    }


public:
    int minCameraCover(TreeNode* root) {
        
        unordered_set<TreeNode*> covered;
        int camCount = 0;
        TreeNode* parent = nullptr;

        covered.insert(nullptr); // add null because this will help for leaf nodes

        dfs(root, parent, covered, camCount);

        return camCount;
    }
};
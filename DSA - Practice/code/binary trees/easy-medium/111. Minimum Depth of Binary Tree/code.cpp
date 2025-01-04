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

- https://leetcode.com/problems/minimum-depth-of-binary-tree/?envType=study-plan-v2&envId=programming-skills

*/
class Solution {

    int height(TreeNode* root) {

        // base condition
        if(root == NULL) return 0;

        // to handle skewed tree case
        if(root->left == nullptr) {
            return 1 + height(root->right);
        }
        else if(root->right == nullptr) {
            return 1 + height(root->left);
        }

        int left = 1 + height(root->left);
        int right = 1 + height(root->right);

        return min(left, right);
    }

public:
    int minDepth(TreeNode* root) {
        return height(root);
    }
};
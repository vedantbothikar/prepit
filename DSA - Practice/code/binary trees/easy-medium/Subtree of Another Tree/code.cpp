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

    bool isSameTree(TreeNode* root, TreeNode* subRoot) {

        if(root == NULL and subRoot == NULL) return true;
        else if(root == NULL or subRoot == NULL or root->val != subRoot->val) return false;

        bool left = isSameTree(root->left, subRoot->left);
        bool right = isSameTree(root->right, subRoot->right);

        return left and right;
    }

    bool checkSubTree(TreeNode* root, TreeNode* subRoot) {

        // base case
        if(root == NULL) return false;

        if(root->val == subRoot->val) {

            if(isSameTree(root, subRoot)) {
                return true;
            }
        }

        bool left = checkSubTree(root->left, subRoot);
        bool right = checkSubTree(root->right, subRoot);

        return left or right;
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(subRoot == NULL) return true;
         
        return checkSubTree(root, subRoot);
    }
};
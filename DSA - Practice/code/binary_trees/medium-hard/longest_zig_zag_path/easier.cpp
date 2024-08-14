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
public:

    void solve(TreeNode* root, int steps, bool goLeft, int &maxSteps) {

        if(root == NULL) return;

        maxSteps = max(maxSteps, steps);

        if(goLeft) {
            solve(root->left, steps+1, false, maxSteps);
            solve(root->right, 1, true, maxSteps);
        }
        else {
            solve(root->right, steps+1, true, maxSteps);
            solve(root->left, 1, false, maxSteps);
        }
    }

    int longestZigZag(TreeNode* root) {

        int maxSteps = 0;
        solve(root, 0, true, maxSteps);
        solve(root, 0, false, maxSteps);
        return maxSteps;
    }
};
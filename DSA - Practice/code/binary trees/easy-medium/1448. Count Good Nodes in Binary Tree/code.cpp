/*

- https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/
- https://neetcode.io/solutions/count-good-nodes-in-binary-tree

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

While dfs, I will keep tracking the maxValue so far till each node, if any time the node's value is greater than or equal to the maxValue, then it is a good node. increment the count

*/
class Solution {

    void dfs(TreeNode* root, int maxValue, int& count) {

        if(root == NULL) return;
        
        if(root->val >= maxValue) count++;

        maxValue = max(maxValue, root->val);
        dfs(root->left, maxValue, count);
        dfs(root->right, maxValue, count);
    }

public:
    int goodNodes(TreeNode* root) {
        
        int count = 0;
        dfs(root, INT_MIN, count);

        return count;
    }
};
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

inorder is used to get the bounds of the subtree
preorder is used to get the node values

TC: O(n)
SC: O(n)

*/

class Solution {

    int preorderIndex = 0;
    unordered_map<int, int> inorderMp;

    TreeNode* dfs(vector<int>& preorder, int start, int end) {

        // base condition
        if(start > end) return nullptr;

        // find index of root
        int rootVal = preorder[preorderIndex];
        int rootIndex = inorderMp[rootVal];
        preorderIndex++;

        // create the node
        TreeNode* root = new TreeNode(rootVal);

        // connect left and right subtrees
        root->left = dfs(preorder, start, rootIndex-1);
        root->right = dfs(preorder, rootIndex+1, end);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = inorder.size();

        // populate inorder values hashmap
        for(int i = 0; i < inorder.size(); i++) {

            int val = inorder[i];
            inorderMp[val] = i;
        }

        return dfs(preorder, 0, n-1);
    }
};
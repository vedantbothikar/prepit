/*

- https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
- 
*/


/*

Intuition
Since inorder traversal of a BST will give us elements in the sorted order, we do an inorder traversal and whenever we encounter the kth element, we store it in the answer

Complexity
Time complexity: O(n)
Space complexity: O(n) // recursive call stack


*/

class Solution {

    void inorder(TreeNode* root, int& k, int& ans) {

        // base condition
        if(root == NULL) return;

        inorder(root->left, k, ans);
        
        k--;
        if(k == 0) ans = root->val;

        inorder(root->right, k, ans);
    }

public:
    int kthSmallest(TreeNode* root, int k) {

        int ans = -1;
        inorder(root, k, ans);

        return ans;        
    }
};
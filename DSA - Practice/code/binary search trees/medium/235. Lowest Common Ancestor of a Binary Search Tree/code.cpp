/*

- https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/


*/


/*

# Complexity
- Time complexity: O(h) // h is height of tree
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(1)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
*/
/*

- if both p and q are greater than than root, then search in right subtree
- else if both p and q are smaller than the root, search in left subtree
- else if there is a split (p and q are in different subtrees): this root is the answer
- else if we found any of the p or q node, which means any of p or q is the root, return that



*/
class Solution {

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        while (
            true) { // since we are guaranteed an answer, we can do while true

            if (p->val > root->val and q->val > root->val)
                root = root->right;
            else if (p->val < root->val and q->val < root->val)
                root = root->left;
            else
                return root;
        }
    }
};
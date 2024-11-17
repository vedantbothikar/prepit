/*
this solution has same complexity but use this solution because 
it will help reduce errors in your code (for some problems I had)
For example: if in the Leetcode: 572. Subtree of Another Tree problem
if you use code.cpp file's code, then it gives errors, there are edge cases to that


This below code is better to use.


*/   
   
   bool isSameTree(TreeNode* root, TreeNode* subRoot) {

        if(root == NULL and subRoot == NULL) return true;
        else if(root == NULL or subRoot == NULL or root->val != subRoot->val) return false;

        // use this style of writing
        bool left = isSameTree(root->left, subRoot->left);
        bool right = isSameTree(root->right, subRoot->right);

        return left and right;
    }
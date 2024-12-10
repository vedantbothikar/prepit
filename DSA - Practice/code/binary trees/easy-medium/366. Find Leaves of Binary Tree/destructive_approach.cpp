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

- https://leetcode.com/problems/find-leaves-of-binary-tree/description/?envType=company&envId=salesforce&favoriteSlug=salesforce-three-months&status=TO_DO&difficulty=MEDIUM


NOTE: This is a more destructive approach where we are deleting nodes and modifying the input. 


What if I dfs and then delete the nodes? delete the memory allocated to the nodes?
And then keep traversing dfs until root == NULL

void dfs(root) {

    if(root == nullptr) return

    if(root == leaf) add to array

    dfs(root->left)
    dfs(root->right)
}


while(root == nullptr) {

    dfs(root)
    ans.push(currlevel leaves)
}


*/
class Solution {

    void dfs(TreeNode* root, TreeNode* parent, vector<int>& currLevelLeaves) {

        // base condition
        if(root == nullptr) return;

        // if leaf found
        if (root->left == nullptr and root->right == nullptr) {

            currLevelLeaves.push_back(root->val);
            
            // delete leaf and mark parent's children as nullptr
            // NOTE: if parent's children are not marked nullptr => dangling pointer problem
            // check whether it is left or right child
            if(parent->left == root) {
                parent->left = nullptr;
            }
            else {  
                parent->right = nullptr;
            }

            delete root;
            return;
        }
        
        dfs(root->left, root, currLevelLeaves);
        dfs(root->right, root, currLevelLeaves);
    }

public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        
        vector<vector<int>> ans;

        while(root != nullptr) {

            vector<int> currLevelLeaves;

            // if root itself is leaf
            if (root->left == nullptr and root->right == nullptr) {
                currLevelLeaves.push_back(root->val);
                ans.push_back(currLevelLeaves);
                break;
            }

            dfs(root, nullptr, currLevelLeaves);

            ans.push_back(currLevelLeaves);
        }

        return ans;
    }
};
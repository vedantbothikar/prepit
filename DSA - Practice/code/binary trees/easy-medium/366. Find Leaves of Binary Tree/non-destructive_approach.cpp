/*

Here intuition is that 

initially all of the leaves will be at the position wherever the 
height of that nodes will be 0
so in `solution`'s 0th index will contain leaves with height 0

then later on, the leaves in second iteration would be the ones which have  
height as 1
so in the 1st index of the `solution` vector, add that leaf

continue doing so


TC: O(N)
SC: O(N)    // recursive call stack


*/


class Solution {
private:

    vector<vector<int>> solution;

public:
    
    int getHeight(TreeNode *root) {
        
        // return -1 for null nodes
        if (!root) {
            return -1;
        }

        // first calculate the height of the left and right children
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        
        // based on the height of the left and right children, obtain the height of the current (parent) node
        int currHeight = max(leftHeight, rightHeight) + 1;
        
        // create space for node located at `currHeight` if not already exists
        if (this->solution.size() == currHeight) {
            this->solution.push_back({});
        }

        // insert the value at the correct position in the solution array
        this->solution[currHeight].push_back(root->val);
        
        // return the height of the current node
        return currHeight;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        this->solution.clear();
        
        getHeight(root);
        
        return this->solution;
    }
};
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


2096. Step-By-Step Directions From a Binary Tree Node to Another
Link: https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/

DFS to get path to startNode
DFS to get path to endNode

concatenate strings by removing the path till their common ancestor (common initials)


*/
class Solution {

    bool dfsPath(TreeNode* root, int nodeToSearch, vector<char>& path) {

        // base case: root is null
        if(root == nullptr) return false;

        // check if found the node
        if(root->val == nodeToSearch) return true;

        // dfs in left and right directions

        // left
        path.push_back('L');
        if (dfsPath(root->left, nodeToSearch, path)) return true;
        path.pop_back();

        // right
        path.push_back('R');
        if (dfsPath(root->right, nodeToSearch, path)) return true;  
        path.pop_back();

        return false;
    }

    vector<char> mergePaths(vector<char> startPath, vector<char> destPath) {
        
        int startLen = startPath.size();
        int destLen = destPath.size();
        vector<char> ans;

        // base cases:
            // if startPath len is 0
            // if destPath len is 0
        if(startLen == 0) return destPath;
        if(destLen == 0) {
            for(int j = 0; j < startLen; j++) {
                ans.push_back('U');
            }
            return ans;
        }

        // reach till lowest common ancestor
        int i = 0;
        while(i < startPath.size() and i < destPath.size()) {
            if(startPath[i] != destPath[i]) break;
            i++;
        }

        // convert all startPath to 'U' and use rest of the destPath as it is
        for(int j = 0; j < startLen - i; j++) {
            ans.push_back('U');
        }

        for(int j = i; j < destLen; j++) {
            char ch = destPath[j];
            ans.push_back(ch);
        }

        return ans;
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        // path to startValue
        vector<char> startPath;
        dfsPath(root, startValue, startPath);

        // path to destValue
        vector<char> destPath;
        dfsPath(root, destValue, destPath);

        // merge the paths by removing the commons
        vector<char> mergedPath = mergePaths(startPath, destPath);
        return string(mergedPath.begin(), mergedPath.end());
    }
};
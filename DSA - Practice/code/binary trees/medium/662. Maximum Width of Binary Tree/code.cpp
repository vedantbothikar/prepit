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

662. Maximum Width of Binary Tree
Link: https://leetcode.com/problems/maximum-width-of-binary-tree/description/

// NOTE: (not used this solution directly, but used logic similar to this)
YT: https://youtu.be/FPzLE2L7uHs?si=WEx3R4aj5zcpv6XY 

// Curr code explanation:
Explanation: https://gist.github.com/vedantbothikar/78ec570f832d3fd81ac1b0f2eec2fbae


*/
class Solution {

    using ll = long long;

public:
    int widthOfBinaryTree(TreeNode* root) {

        queue<pair<TreeNode*, ll>> q;  // {TreeNode*, nodeIdx}

        // at this level, the root node is the first node
        // so, we gave it index of 1
        q.push({root, 1});  
        q.push({nullptr, 0});   // nullptr are just for separation, so we give it idx = 0

        ll maxWidth = 0;
        bool startingNewLevel = true;

        ll startIdx = 0;
        ll prevIdx = 0;

        // perform bfs
        while(!q.empty()) {

            // pop the front
            TreeNode* currNode = q.front().first;
            ll currIdx = q.front().second;
            q.pop();

            // check if curr level completed traversing
            if(currNode == nullptr) {

                // calculate the maxWidth of this level we just traversed
                // NOTE: prevIdx will now be pointing to last node of this level
                // since it is the lastNode index, it will also be equal to the width of this level
                maxWidth = max(maxWidth, prevIdx);
                startingNewLevel = true;

                // insert level separator if still elements left
                if(!q.empty()) {
                    q.push({nullptr, 0});
                }

                continue;   // IMP;
            }

            if(startingNewLevel) {
                startIdx = currIdx;
                startingNewLevel = false;
            }

            // NOTE: we have to do index normalization to avoid int overflow
            // Explanation: https://gist.github.com/vedantbothikar/78ec570f832d3fd81ac1b0f2eec2fbae?permalink_comment_id=5922452#gistcomment-5922452
            // In simple terms it means that for every level
            // we start the index again from 1,2,3,.... (FOR EVERY LEVEL!!)

            ll normalizedCurrIdx = currIdx - startIdx + 1;

            // add children nodes
            if(currNode->left) {
                q.push({currNode->left, normalizedCurrIdx*2});
            }

            if(currNode->right) {
                q.push({currNode->right, normalizedCurrIdx*2 + 1});
            }

            prevIdx = normalizedCurrIdx;
        }

        return maxWidth;
    }
};
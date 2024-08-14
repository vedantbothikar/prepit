/*

https://www.youtube.com/watch?v=bAO794rh_4M&t=11s

Watch video

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
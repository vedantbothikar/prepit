

#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    void solve(TreeNode *leftNode, TreeNode *rightNode, bool &ans)
    {

        // base case
        if ((leftNode == NULL and rightNode == NULL) or ans == false)
        {
            return;
        }

        if (!leftNode or !rightNode)
        {
            ans = false;
            return;
        }

        if (leftNode->val != rightNode->val)
        {
            ans = false;
            return;
        }

        solve(leftNode->right, rightNode->left, ans);
        solve(leftNode->left, rightNode->right, ans);
    }

public:
    bool isSymmetric(TreeNode *root)
    {

        bool ans = true;

        if (root == NULL)
        {
            return true;
        }

        solve(root->left, root->right, ans);
        return ans;
    }
};

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

/*
you can also solve this using BFS
(level order traversal)
*/

class Solution
{

private:
    void inorder(TreeNode *root, bool left, int &sum)
    {

        // base case
        if (root == NULL)
        {
            return;
        }

        inorder(root->left, true, sum);
        inorder(root->right, false, sum);

        if (root->left == NULL and root->right == NULL and left == true)
        {
            sum += root->val;
        }
    }

public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        int sum = 0;
        bool left = false;
        inorder(root, left, sum);
        return sum;
    }
};

int main()
{

    return 0;
}
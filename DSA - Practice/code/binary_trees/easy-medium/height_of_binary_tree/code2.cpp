#include <bits/stdc++.h>
using namespace std;

/*
 Here we are using recursion
 logic is that the height of the tree will be
 equal to the maximum of the heights of the left and right subtrees
 +1 (this is because we are choosing the subtrees and leaving out the root node)



For example:
        1
    2      3
3

In this tree
the maximum height is calculated by the max height of the
left subtree of root and right subtree of root +1 (we are considering root as well in the height... soo)

checkout notes
\/


so in the code we are finding the height of each and every node
and using them to calculate the height of the whole tree

*/

int maxDepth(TreeNode *root)
{

    // base case
    if (root == NULL)
    {
        return 0;
    }

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    int height = max(left, right) + 1;

    return height;
}
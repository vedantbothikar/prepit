#include <bits/stdc++.h>
using namespace std;

// Look for explanation online (in case required)
// difficult to explain

// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/

int inorder(TreeNode *root, int direction, int &finalMax)
{

    // base case
    if (root == NULL)
    {
        return 0;
    }

    // WORK for current
    if (direction == 1)
    {
        int left = inorder(root->left, 1, finalMax);
    }
    else if (direction == 2)
    {
        int right = inorder(root->right, 2, finalMax);
    }
    else if (direction == 3)
    {
        int left = inorder(root->left, 1, finalMax);
        int right = inorder(root->right, 2, finalMax);
        int currMax = max(left, right);
        finalMax = max(finalMax, currMax);
    }

    // WORK for previous
    // go left
    if (direction == 1)
    {
        // go right for next iteration
        direction = 2;
        int prevLength = inorder(root->right, direction, finalMax) + 1;
        finalMax = max(finalMax, prevLength);
        return prevLength;
    }
    // go right
    else if (direction == 2)
    {
        // go left for next iteration
        direction = 1;
        int prevLength = inorder(root->left, direction, finalMax) + 1;
        finalMax = max(finalMax, prevLength);
        return prevLength;
    }

    return finalMax;
}

class Solution
{
public:
    int longestZigZag(TreeNode *root)
    {

        int direction = 3;
        int finalMax = 0;
        return inorder(root, direction, finalMax);
    }
};

int main()
{

    return 0;
}
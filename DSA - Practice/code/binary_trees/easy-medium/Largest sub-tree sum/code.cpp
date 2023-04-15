#include <bits/stdc++.h>
using namespace std;

/*
https://www.codingninjas.com/codestudio/problems/largest-sub-tree-sum_920400?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_11

*/

#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int solve(TreeNode<int> *root, int &maxsum)
{

    // base case
    if (root == NULL)
    {
        return 0;
    }

    int ls = solve(root->left, maxsum);
    int rs = solve(root->right, maxsum);

    int currsum = ls + rs + root->data;

    maxsum = max(maxsum, currsum);

    return currsum;
}

int largestSubtreeSum(TreeNode<int> *root)
{
    // Write your code here.

    int maxsum = INT_MIN;
    solve(root, maxsum);
    return maxsum;
}

int main()
{

    return 0;
}
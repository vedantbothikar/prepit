#include <bits/stdc++.h>
using namespace std;

/*

https://www.codingninjas.com/codestudio/problems/maximum-path-sum_3125903?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_11
*/

/************************************************************

   Following is the TreeNode class structure

   class TreeNode {
    public:
        int data;
        vector<TreeNode*> children;

        TreeNode(int data) {
            this->data = data;
        }
   }

************************************************************/

void solve(TreeNode *root, int currsum, int &maxsum)
{

    // base case
    if (root == NULL)
    {
        return;
    }

    currsum = currsum + root->data;

    // if reached to a leaf node
    if (root->children.size() == 0)
    {
        // check if currsum is greater than max

        if (currsum > maxsum)
        {
            maxsum = currsum;
        }
    }

    for (auto i : root->children)
    {
        solve(i, currsum, maxsum);
    }
}

int findMaxSum(int n, TreeNode *root)
{
    // Write your code here.

    int maxsum = root->data;

    solve(root, 0, maxsum);
    return maxsum;
}

int main()
{

    return 0;
}
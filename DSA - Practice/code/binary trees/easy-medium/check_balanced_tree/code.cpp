#include <bits/stdc++.h>
using namespace std;

/*
- https://leetcode.com/problems/balanced-binary-tree/description/

Approach is that we are finding the height of the tree
for each and every node already
(check the code of height of tree, in that to find the height of a tree,
you aare already finding the height of each and every node)


NOW, it is asked that the difference between the left and right subtree's height
should NOT be greater than 1, and this should be true for all the nodes


So, as we are already finding the height of all the nodes,
NOW we ONLY have to have an additional check on the recursion code
we have to have a check to check if the difference is how we want it to be

if the difference is not how we want it to bee
then we are setting the variable's value as 0

and finally checking the value of this variable to decide our final answer

*/

class Solution
{

private:
    int height(Node *root, int &ans)
    {

        // base case
        if (root == NULL)
        {
            return 0;
        }

        int lh = height(root->left, ans);
        int rh = height(root->right, ans);

        if (abs(lh - rh) > 1)
        {
            ans = 0;
        }

        return max(lh, rh) + 1;
    }

public:
    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here

        int ans = 1;

        height(root, ans);

        return ans;
    }
};

int main()
{

    return 0;
}
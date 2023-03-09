#include <bits/stdc++.h>
using namespace std;

/*

Approach is that  similar to how to find height you were traversing
each and every element as you were doing it in inorder traversal


similarly visit all elements
just keep the check of the sum

and return the latest sum (sum of children + current value)



*/

class Solution
{
private:
    int traverseTree(Node *root, bool &ans)
    {

        if (root == NULL or ans == false)
        {
            return 0;
        }

        // leaf node
        if (root->left == NULL and root->right == NULL)
        {
            return root->data;
        }

        int left = traverseTree(root->left, ans);
        int right = traverseTree(root->right, ans);

        if (left + right != root->data)
        {
            ans = false;
        }

        return left + right + root->data;
    }

public:
    bool isSumTree(Node *root)
    {
        // Your code here

        bool ans = true;
        int currsum = 0;

        if (root == NULL)
        {
            return true;
        }

        traverseTree(root, ans);

        return ans;
    }
};

int main()
{

    return 0;
}
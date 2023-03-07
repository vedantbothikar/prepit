#include <bits/stdc++.h>
using namespace std;

int heightOfTree(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }

    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);

    return max(left, right) + 1;
}

// Function to return the diameter of a Binary Tree.
int diameter(Node *root)
{
    // Your code here

    if (root == NULL)
    {
        return 0;
    }

    int opt1 = diameter(root->left);
    int opt2 = diameter(root->right);
    int opt3 = heightOfTree(root->left) + heightOfTree(root->right) + 1;

    return max(opt1, max(opt2, opt3));
}

int main()
{

    return 0;
}
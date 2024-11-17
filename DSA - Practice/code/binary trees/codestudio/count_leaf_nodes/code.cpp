#include <bits/stdc++.h>
using namespace std;

void inorder(BinaryTreeNode<int> *root, int &count)
{

    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }
    else
    {
        inorder(root->left, count);
        inorder(root->right, count);
    }
}

int noOfLeafNodes(BinaryTreeNode<int> *root)
{
    // Write your code here.

    int count = 0;
    inorder(root, count);

    return count;
}

int main()
{

    return 0;
}
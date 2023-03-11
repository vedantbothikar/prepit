#include <bits/stdc++.h>
using namespace std;

// doing inorder, preorder ans postorder all in single traversal

void traverse(BinaryTreeNode<int> *root, vector<int> &ino, vector<int> &pre, vector<int> &post)
{

    // base case
    if (root == NULL)
    {
        return;
    }

    pre.push_back(root->data);
    traverse(root->left, ino, pre, post);
    ino.push_back(root->data);
    traverse(root->right, ino, pre, post);
    post.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here.

    vector<int> ino;
    vector<int> pre;
    vector<int> post;

    traverse(root, ino, pre, post);

    /*
    inorder(root, ino);
    preorder(root, pre);
    postorder(root, post);
    */

    vector<vector<int>> ans;
    ans.push_back(ino);
    ans.push_back(pre);
    ans.push_back(post);

    return ans;
}

int main()
{

    return 0;
}
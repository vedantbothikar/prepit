#include <bits/stdc++.h>
using namespace std;

/*

https://www.codingninjas.com/codestudio/problems/convert-binary-tree-to-mirror-tree_873140?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_11

*/

#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

/*
check by replacing root->left with right in every level order
*/

void solve(BinaryTreeNode<int> *root)
{

    // base case
    if (root == NULL)
    {
        return;
    }

    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {

        BinaryTreeNode<int> *curr = q.front();
        q.pop();

        BinaryTreeNode<int> *temp = curr->left;

        curr->left = curr->right;
        curr->right = temp;

        if (curr->left)
        {
            q.push(curr->left);
        }
        if (curr->right)
        {
            q.push(curr->right);
        }
    }
}

void mirrorTree(BinaryTreeNode<int> *root)
{
    // Write your code here.

    solve(root);
}

int main()
{

    return 0;
}
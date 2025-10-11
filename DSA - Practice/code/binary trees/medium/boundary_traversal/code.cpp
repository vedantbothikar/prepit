#include <bits/stdc++.h>
using namespace std;

/*

https://www.codingninjas.com/codestudio/problems/boundary-traversal_790725?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

APPROACH:

1]take all the left side nodes
except the leaf node (the leftmost node) (this will be included in the lead nodes category)

2] take alll the leaf nodes

3] take all the right nodes
except the leaf node (the rightmost node)

the right nodes should be in reverse order,
so store them in the array when you complete traversing
and you are on your way back
OR,
you can (similar to left side nodes) add the nodes in
a separate vector then reverse the vector at last and
then merge that reversed vector with the
ans vector -- this is done in code2.cpp



*/

#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void traverseLeft(TreeNode<int> *root, vector<int> &ans)
{

    // base case
    if (root == NULL)
    {
        return;
    }

    // if it is not leaf node
    if (!(root->left == NULL and root->right == NULL))
    {
        ans.push_back(root->data);
    }

    if (root->left)
    {
        traverseLeft(root->left, ans);
    }
    else
    {
        traverseLeft(root->right, ans);
    }
}

void traverseLeaf(TreeNode<int> *root, vector<int> &ans)
{

    // base case
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL and root->right == NULL)
    {
        ans.push_back(root->data);
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(TreeNode<int> *root, vector<int> &ans)
{

    // base case
    if (root == NULL)
    {
        return;
    }

    if (root->right)
    {
        traverseRight(root->right, ans);
    }
    else
    {
        traverseRight(root->left, ans);
    }

    // if not leaf node
    // this will add the nodes to the ans in reverse order in the traversal's way back
    if (!(root->left == NULL and root->right == NULL))
    {
        ans.push_back(root->data);
    }
}

void solve(TreeNode<int> *root, vector<int> &ans)
{

    // base cases
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL and root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    ans.push_back(root->data);

    traverseLeft(root->left, ans);
    traverseLeaf(root, ans);
    traverseRight(root->right, ans);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    // Write your code here.

    vector<int> ans;
    solve(root, ans);
    return ans;
}

int main()
{

    return 0;
}
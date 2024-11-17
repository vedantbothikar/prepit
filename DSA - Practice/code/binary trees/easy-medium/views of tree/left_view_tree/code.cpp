#include <bits/stdc++.h>
using namespace std;

// Function to return a list containing elements of left view of the binary tree.

// keep going on the left and print these left nodes
// if left is NULL, then go to right and print it
// but in the next iteration again first check for left nodes
// stop when you reach a leaf node or the
// boolean value on when to stop, whenever leaf node is reached, change this value

// in case the height of right subtree (of the root) is greater than the height of
// left subtree, then we need to first explore left subtree and then exlpore
// the right subtree... the right subtree should be exploreed below the level
// which is equal to the height of the left subtree

// for trees like:
// 4 5 2 N N 3 1 6 7
// THIS occurs when the height of left subtree of the root is greater than height of right subtree of root
// need a height function
// need a function which will give the node at a certain height in the right subtree

int height(Node *root)
{

    // base case
    if (root == NULL)
    {
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh, rh) + 1;
}

Node *nodeToBeFound;

void findNode(Node *root, int findLevel, int currLevel, bool &stopFind)
{

    // base case
    if (root == NULL or stopFind == true)
    {
        return;
    }

    if (findLevel == currLevel)
    {
        nodeToBeFound = root;
        stopFind = true;
        return;
    }

    findNode(root->left, findLevel, ++currLevel, stopFind);
    findNode(root->right, findLevel, ++currLevel, stopFind);
}

void solve(Node *root, vector<int> &ans, bool &stop, bool &exploreRight)
{

    // base case
    if (root == NULL or stop == true)
    {
        return;
    }

    ans.push_back(root->data);

    if (root->left)
    {
        solve(root->left, ans, stop, exploreRight);
    }
    else if (root->right)
    {
        solve(root->right, ans, stop, exploreRight);
    }
    else if (exploreRight)
    {

        // cout<< "inside exploring right when root is: "<< root->data << endl;
        // cout<<"node to be found: "<< nodeToBeFound->data<<endl;

        exploreRight = false;

        if (nodeToBeFound->left)
        {
            solve(nodeToBeFound->left, ans, stop, exploreRight);
        }
        else if (root->right)
        {
            solve(nodeToBeFound->right, ans, stop, exploreRight);
        }
    }
    else
    {
        // leaf node reached

        // cout<< "leaf reached when: " << root->data <<endl;
        stop = true;
    }
}

vector<int> leftView(Node *root)
{
    // Your code here

    bool stop = false;
    bool exploreRight = false;
    bool stopFind = false;
    vector<int> ans;

    // base case
    if (root == NULL)
    {
        return ans;
    }

    // check if height of right subtree is greater than the height of left subtree
    int lh = height(root->left);
    int rh = height(root->right);

    if (lh - rh < 0)
    {
        exploreRight = true;
        findNode(root->right, lh, 1, stopFind);
    }

    solve(root, ans, stop, exploreRight);
    return ans;
}

int main()
{

    return 0;
}
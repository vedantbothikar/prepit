#include <bits/stdc++.h>
using namespace std;

/*

BINARY TREES

https://www.codingninjas.com/codestudio/problems/leaves-at-same-level_920389?topList=jp-morgan-interview-questions

THIS IS SOLVED USING DFS
BUT it passes only 9/11 test cases


*/

#include <bits/stdc++.h>
/*

    Following is the Tree node structure for you referance:

    class TreeNode{
    public :
        int data;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*/

// currHeight initial = 0
void inorder(TreeNode<int> *root, int &leafLvl, bool &ans, int currHeight)
{

    // base case
    // when leaf node is reached

    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL and root->right == NULL)
    {

        if (leafLvl == -1)
        {
            leafLvl = currHeight;
            ans = true;
        }
        else if (leafLvl == currHeight)
        {
            ans = true;
        }
        else
        {
            ans = false;
        }

        return;
    }

    inorder(root->left, leafLvl, ans, currHeight + 1);
    inorder(root->right, leafLvl, ans, currHeight + 1);
}

bool CheckLeafLevel(TreeNode<int> *root)
{

    // Write your code here

    if (root == NULL)
    {
        return true;
    }

    bool ans = true;
    int leafLvl = -1;

    inorder(root, leafLvl, ans, 0);

    return ans;
}

int main()
{

    return 0;
}
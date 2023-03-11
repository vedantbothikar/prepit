#include <bits/stdc++.h>
using namespace std;

void levelOrder(BinaryTreeNode<int> *root, vector<int> &ans)
{

    // base case
    if (root == NULL)
    {
        return;
    }

    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);

    BinaryTreeNode<int> *prev = NULL;

    while (!q.empty())
    {

        BinaryTreeNode<int> *curr = q.front();
        q.pop();

        if (curr == NULL)
        {

            ans.push_back(prev->data);

            prev = curr;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {

            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }

            prev = curr;
        }
    }
}

vector<int> printRightView(BinaryTreeNode<int> *root)
{
    // Write your code here.

    vector<int> ans;
    levelOrder(root, ans);
    return ans;
}

int main()
{

    return 0;
}
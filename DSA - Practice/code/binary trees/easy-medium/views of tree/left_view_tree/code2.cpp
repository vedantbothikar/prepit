

#include <bits/stdc++.h>
using namespace std;

/*

Approach is that the nodes are the first in every level

WHICH means we have to do level order traversal and store every first
node in every level



*/

void levelOrder(Node *root, vector<int> &ans)
{

    // base case
    if (root == NULL)
    {
        return;
    }

    Node *prev = NULL;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {

        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            prev = NULL;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {

            if (prev == NULL)
            {
                ans.push_back(temp->data);
            }

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }

            prev = temp;
        }
    }
}

vector<int> leftView(Node *root)
{
    // Your code here

    vector<int> ans;
    levelOrder(root, ans);
    return ans;
}
/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    void levelOrderTraversal(struct Node *root, int &count)
    {

        queue<Node *> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty())
        {

            Node *temp = q.front();
            q.pop();

            if (temp == NULL)
            {
                count++;

                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {

                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
    }

public:
    // Function to find the height of a binary tree.
    int height(struct Node *node)
    {
        // code here
        int count = 0;

        levelOrderTraversal(node, count);

        return count;
    }
};
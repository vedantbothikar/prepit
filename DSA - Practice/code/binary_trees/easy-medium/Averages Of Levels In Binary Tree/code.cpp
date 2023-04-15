#include <bits/stdc++.h>
using namespace std;

/*
https://www.codingninjas.com/codestudio/problems/averages-of-levels-in-binary-tree_893192?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_11


*/

#include <bits/stdc++.h>
/********************************

    Following is the Binary Tree node structure

    class BinaryTreeNode {
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

********************************/

void solve(BinaryTreeNode<int> *root, vector<long long> &ans)
{

    // base case
    if (root == NULL)
    {
        return;
    }

    long long sum = 0;
    long long count = 0;

    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {

        BinaryTreeNode<int> *curr = q.front();
        q.pop();

        if (curr == NULL)
        {

            long long avg = sum / count;
            ans.push_back(avg);

            sum = 0;
            count = 0;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {

            sum += curr->data;
            count += 1;

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
}

vector<long long> averageOfLevels(BinaryTreeNode<int> *root)
{
    // Write your code here.

    vector<long long> ans;
    solve(root, ans);
    return ans;
}

int main()
{

    return 0;
}
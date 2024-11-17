#include <bits/stdc++.h>
using namespace std;

/*

https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

*/

class Solution
{

private:
    // storing all the nodes level wise
    // one level in vector `partans`
    // all levels in vector `allans`

    vector<vector<int>> levelOrder(Node *root)
    {

        vector<vector<int>> allans;

        // base case
        if (root == NULL)
        {
            return allans;
        }

        vector<int> partans;

        queue<Node *> q;
        q.push(root);
        q.push(NULL);

        bool leftToRight = true;

        while (!q.empty())
        {

            Node *temp = q.front();
            q.pop();

            if (temp == NULL)
            {

                allans.push_back(partans);
                partans.clear();

                leftToRight = false;
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                partans.push_back(temp->data);

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

        return allans;
    }

    // this will store all the elements from allans into finalans is proper order
    // change the order of vectors with index that are odd

    void zigZagOrder(vector<vector<int>> allans, vector<int> &finalans)
    {

        // for every odd iteration, reverse the vector

        for (int i = 0; i < allans.size(); i++)
        {

            if (i & 1)
            {
                // odd

                for (int j = allans[i].size() - 1; j >= 0; j--)
                {
                    finalans.push_back(allans[i][j]);
                }
            }
            else
            {
                // even

                for (int j = 0; j < allans[i].size(); j++)
                {
                    finalans.push_back(allans[i][j]);
                }
            }
        }
    }

    void solve(Node *root, vector<int> &finalans)
    {

        vector<vector<int>> allans = levelOrder(root);
        zigZagOrder(allans, finalans);
    }

public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node *root)
    {
        // Code here

        vector<int> finalans;
        solve(root, finalans);
        return finalans;
    }
};

int main()
{

    return 0;
}
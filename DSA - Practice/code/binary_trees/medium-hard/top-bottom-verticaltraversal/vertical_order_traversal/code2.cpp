#include <bits/stdc++.h>
using namespace std;

/*

DIFFERENCE here is that we have to sort the elements inside the same row and col

*/

/*
987. Vertical Order Traversal of a Binary Tree
- https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

data structure:

map<int, map<int, multiset<int>>>

first int - col
second int - row
multiset - stores all the values of a particular col and row

we chose multiset instead of vector because we want to sort the elements
inside the same row and col

at last we will merge all the sets in a single col


*/

class Solution
{

private:
    void levelOrder(TreeNode *root, map<int, map<int, multiset<int>>> &m)
    {

        // base case
        if (root == NULL)
        {
            return;
        }

        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty())
        {

            TreeNode *temp = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            // add to map
            m[col][row].insert(temp->val);

            if (temp->left)
            {
                q.push({temp->left, {row + 1, col - 1}});
            }
            if (temp->right)
            {
                q.push({temp->right, {row + 1, col + 1}});
            }
        }
    }

    void mergeAns(map<int, map<int, multiset<int>>> m, vector<vector<int>>
                                                           &ans)
    {

        // merge all the multisets of every row in a col of the map

        // accessing every col
        for (auto i : m)
        {

            vector<int> temp;

            for (auto j : i.second)
            {
                temp.insert(temp.end(), j.second.begin(), j.second.end());
            }

            ans.push_back(temp);
        }
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {

        map<int, map<int, multiset<int>>> m;
        vector<vector<int>> ans;

        levelOrder(root, m);
        mergeAns(m, ans);
        return ans;
    }
};

int main()
{

    return 0;
}
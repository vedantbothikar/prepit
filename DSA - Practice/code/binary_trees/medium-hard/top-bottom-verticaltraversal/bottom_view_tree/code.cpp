#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    void levelOrder(Node *root, map<int, int> &m)
    {

        // base case
        if (root == NULL)
        {
            return;
        }

        queue<pair<Node *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {

            Node *temp = q.front().first;
            int hdis = q.front().second;
            q.pop();

            m[hdis] = temp->data;

            if (temp->left)
            {
                q.push({temp->left, hdis - 1});
            }
            if (temp->right)
            {
                q.push({temp->right, hdis + 1});
            }
        }
    }

    void mergeIntoVector(map<int, int> m, vector<int> &ans)
    {

        for (auto i : m)
        {
            ans.push_back(i.second);
        }
    }

public:
    vector<int> bottomView(Node *root)
    {
        // Your Code Here

        map<int, int> m;
        vector<int> ans;
        levelOrder(root, m);
        mergeIntoVector(m, ans);
        return ans;
    }
};

int main()
{

    return 0;
}
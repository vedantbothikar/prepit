#include <bits/stdc++.h>
using namespace std;

/*


- https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
- https://www.codingninjas.com/codestudio/problems/799401?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

*/

class Solution
{

private:
    /*

    map-
    - first element is for hdis
    - second element is for the tree's value

    for every node, we are just checking if the value in the map
    exists

    for upper levels in the tree, the values may note exists
     and we need to add them in the tree

     for lower levels, most of the values will already be there
     so mostly the ndoes inthe exteremes will be added


     NOTE: we cannot simply add the values of the extremnes of every
     level BECAUSE
....
(some reason i forgot)



    */

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

            // check if the value in the map exists for this hdis

            if (!m.count(hdis))
            {
                m[hdis] = temp->data;
            }

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

    void makeVectorFromMap(map<int, int> m, vector<int> &ans)
    {

        for (auto &i : m)
        {
            ans.push_back(i.second);
        }
    }

public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        // Your code here

        map<int, int> m;
        vector<int> ans;
        levelOrder(root, m);
        makeVectorFromMap(m, ans);
        return ans;
    }
};

int main()
{

    return 0;
}
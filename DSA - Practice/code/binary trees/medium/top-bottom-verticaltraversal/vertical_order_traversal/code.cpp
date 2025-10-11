#include <bits/stdc++.h>
using namespace std;

/*

GFG and Codestudio problems are similar
but in Leetcode, you need to sort accordingly (when there are multiple values in the same row and col) (check test case 3 in leetcode)

- https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
- https://www.codingninjas.com/codestudio/problems/vertical-order-traversal_920533?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0


*/

class Solution
{

private:
    /*
    In this function we are going to iterate over the tree
    and store the elements into the vector inside of the map
    such that the elemtns correspond to the hdis
    hdis -> horizontal distance

    so the map will be:

    -2 : [ 1,2,3,4,5],
    -1 : [6,7,8,],
    0 : [9, 10],
    1 : [11, 12, 13, 14]


    and we should use map instead of unordered map
    or else while merging we will have to sort the keys
    we WANT the keys to be sorted


    when you traverse left, reduce the hdis by 1
    when you traverse right, increase the hdis by 1

    */

    /*

    IMPORTANT POINT:

    solving using BFS will work but using DFS wont work

    BECASUE: using DFS, you will not get the correct ORDER of nodes
    as per question you are required to print the correct order
    of the nodes as well

    so you will have to apply BFS

    */

    void solveUsingDFS(Node *root, int hdis, map<int, vector<int>> &m)
    {

        // base case
        if (root == NULL)
        {
            return;
        }

        m[hdis].push_back(root->data);
        solveUsingDFS(root->left, hdis - 1, m);
        solveUsingDFS(root->right, hdis + 1, m);
    }

    void mergeVectors(map<int, vector<int>> m, vector<int> &ans)
    {

        for (auto i = m.begin(); i != m.end(); i++)
        {
            ans.insert(ans.end(), i->second.begin(), i->second.end());
        }
    }

    void solveUsingBFS(Node *root, map<int, vector<int>> &m)
    {

        // base case
        if (root == NULL)
        {
            return;
        }

        // the seecond element of the pair is horizontal distance
        queue<pair<Node *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {

            Node *temp = q.front().first;
            int hdis = q.front().second;
            q.pop();

            m[hdis].push_back(temp->data);

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

public:
    // Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        // Your code here

        vector<int> ans;

        // the first element (key) in this map is horizontal distance
        map<int, vector<int>> m;
        int hdis = 0;

        // solveUsingDFS(root, 0, m);
        solveUsingBFS(root, m);
        mergeVectors(m, ans);

        return ans;
    }
};

int main()
{

    return 0;
}
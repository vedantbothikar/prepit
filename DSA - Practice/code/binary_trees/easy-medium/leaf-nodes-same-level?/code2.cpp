
/*

This is using BFS technique

This passes all of the test cases

*/

bool solveBFS(TreeNode<int> *root)
{

    // base case
    if (root == NULL)
    {
        return true;
    }

    queue<TreeNode<int> *> q;
    q.push(root);
    q.push(NULL);

    bool leafFound = false;
    bool ans = true;
    int currHeight = 0;
    int leafLvl = -1;

    while (!q.empty())
    {

        TreeNode<int> *temp = q.front();
        q.pop();

        if (temp == NULL)
        {

            currHeight++;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {

            // if leaf node
            if (temp->left == NULL and temp->right == NULL)
            {

                if (leafLvl == -1)
                {
                    leafLvl = currHeight;
                }
                else if (leafLvl == currHeight)
                {
                    ans = true;
                }
                else
                {
                    ans = false;
                }
            }

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

    return ans;
}

bool CheckLeafLevel(TreeNode<int> *root)
{

    // Write your code here

    if (root == NULL)
    {
        return true;
    }

    return solveBFS(root);
}

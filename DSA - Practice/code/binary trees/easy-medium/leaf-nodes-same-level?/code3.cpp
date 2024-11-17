
void solveByMap(TreeNode<int> *root, int height, unordered_map<int, int> &m)
{

    if (root == NULL)
    {
        return;
    }

    // if leaf node
    if (root->left == NULL and root->right == NULL)
    {
        if (m[height])
        {
            m[height]++;
        }
        else
        {
            m[height] = 1;
        }
    }

    solveByMap(root->left, height + 1, m);
    solveByMap(root->right, height + 1, m);
}

bool CheckLeafLevel(TreeNode<int> *root)
{

    // Write your code here

    if (root == NULL)
    {
        return true;
    }

    unordered_map<int, int> m;

    solveByMap(root, 0, m);

    if (m.size() > 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

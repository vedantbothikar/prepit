class Solution
{

private:
    void traverseLeft(Node *root, vector<int> &leftNodes)
    {

        // base case
        if (root == NULL)
        {
            return;
        }

        // if not leaf node
        if (!(root->left == NULL and root->right == NULL))
        {
            leftNodes.push_back(root->data);
        }

        if (root->left)
        {
            traverseLeft(root->left, leftNodes);
        }
        else
        {
            traverseLeft(root->right, leftNodes);
        }
    }

    void traverseLeaf(Node *root, vector<int> &leafNodes)
    {

        if (root == NULL)
        {
            return;
        }

        if (root->left == NULL and root->right == NULL)
        {
            leafNodes.push_back(root->data);
        }

        traverseLeaf(root->left, leafNodes);
        traverseLeaf(root->right, leafNodes);
    }

    void traverseRight(Node *root, vector<int> &rightNodes)
    {

        // base case
        if (root == NULL)
        {
            return;
        }

        // not leaf
        if (!(root->left == NULL and root->right == NULL))
        {
            rightNodes.push_back(root->data);
        }

        if (root->right)
        {
            traverseRight(root->right, rightNodes);
        }
        else
        {
            traverseRight(root->left, rightNodes);
        }
    }

    vector<int> solveUsingDFS(Node *root)
    {

        vector<int> ans;

        // base cases
        if (root == NULL)
        {
            return ans;
        }
        if (root->left == NULL and root->right == NULL)
        {
            ans.push_back(root->data);
            return ans;
        }

        vector<int> rightNodes;

        ans.push_back(root->data);

        // NOTE: for traverse left I am sending root->left because the left boudnary nodes are only the ones that will be present in the left subtree of the root, read the question
        traverseLeft(root->left, ans);
        traverseLeaf(root, ans);
        traverseRight(root->right, rightNodes);

        // reverse rightNodes
        // merge vectors
        reverse(rightNodes.begin(), rightNodes.end());
        ans.insert(ans.end(), rightNodes.begin(), rightNodes.end());

        return ans;
    }

public:
    vector<int> boundary(Node *root)
    {

        // Your code here
        return solveUsingDFS(root);
    }
};
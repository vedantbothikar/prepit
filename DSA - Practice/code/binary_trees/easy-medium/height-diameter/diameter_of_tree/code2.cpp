
// This is
// TC O(N)
// SC O(N)  -> recursive function call stack

/*

Here our approach is that we are considering
each and every node as a root node once
and then we have to find the **height of the left and right subtrees** of
all of these nodes
diameter of the current node can be found by lh + rh + 1

it means that we are calculating the diameter for each and every node
and then choosing the once with the maximum value


the diameter will be the
maximum of all of the diameters calculated so far




*/

class Solution
{

private:
    int heightOfTree(Node *root, int &diameter)
    {

        if (root == NULL)
        {
            return 0;
        }

        int lh = heightOfTree(root->left, diameter);
        int rh = heightOfTree(root->right, diameter);

        diameter = max(diameter, lh + rh + 1);

        return max(lh, rh) + 1;
    }

public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node *root)
    {
        // Your code here

        int diameter = 0;
        heightOfTree(root, diameter);
        return diameter;
    }
};
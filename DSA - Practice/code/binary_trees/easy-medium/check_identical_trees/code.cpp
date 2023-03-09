#include <bits/stdc++.h>
using namespace std;

/*

Approach is that we can do any type of traversal as we have done earlier

Only this time during the traversal you have to also check if the
values are same or not

*/

class Solution
{
private:
    void inorder(Node *r1, Node *r2, bool &ans)
    {

        // check if values are equal

        if (ans == false)
        {
            return;
        }

        // handling NULL values
        if (r1 == NULL and r2 == NULL)
        {
            return;
        }
        if (r1 == NULL or r2 == NULL)
        {
            // either one of them is NULL
            // both can't be NULL here bcuz we have checked it above
            ans = false;
            return;
        }
        // checking data when there are no NULL values
        if (r1->data != r2->data)
        {
            ans = false;
            return;
        }

        inorder(r1->left, r2->left, ans);
        inorder(r1->right, r2->right, ans);
    }

public:
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        // Your Code here

        bool ans = true;

        inorder(r1, r2, ans);
        return ans;
    }
};

int main()
{

    return 0;
}
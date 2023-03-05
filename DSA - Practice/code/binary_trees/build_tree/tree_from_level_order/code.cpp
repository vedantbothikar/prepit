// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// if data = -1 we are considering here that is NULL

node *buildTree(node *root)
{

    cout << "ENTER data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "ENTER data for left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "ENTER data for right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void preorder(node *root)
{

    // base case
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{

    // base case
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(node *root)
{

    // base case
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// THIS IS THE CODE RELEVANT HERE

void buildFromLevelOrderTraversal(node *&root)
{

    queue<node *> q;

    cout << "Enter data for root: " << endl;
    int rootData;
    cin >> rootData;

    root = new node(rootData); // CORRECT
    // root->data = rootData    // WRONG

    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        // Enter data in left of temp
        cout << "Enter data in the left of " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        // Enter data in right of temp
        cout << "Enter data for right of " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int main()
{
    // Write C++ code here

    node *root = NULL;

    buildFromLevelOrderTraversal(root);

    // root = buildTree(root);

    cout << "INORDER: " << endl;
    inorder(root);
    cout << endl;

    cout << "PREORDER: " << endl;
    preorder(root);
    cout << endl;

    cout << "POSTORDER: " << endl;
    postorder(root);
    cout << endl;

    return 0;
}

// input
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
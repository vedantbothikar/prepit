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

int main()
{
    // Write C++ code here

    node *root = NULL;
    root = buildTree(root);

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
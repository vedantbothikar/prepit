// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

// TREEE TRAVERSAL USING RECURSION

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

int main()
{
    // Write C++ code here

    node *root = NULL;
    root = buildTree(root);

    return 0;
}
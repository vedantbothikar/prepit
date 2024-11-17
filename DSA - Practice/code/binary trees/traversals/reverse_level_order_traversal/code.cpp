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

// We are using queue here

void levelOrderTraversal(node *root)
{

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();
        cout << temp->data << " ";

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

// For this we have used Stack as well as Queue

void reverseLevelOrderTraversal(node *root)
{

    queue<node *> q;
    q.push(root);
    stack<node *> s;

    //

    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();
        s.push(temp);

        if (temp->right)
        {
            q.push(temp->right);
        }

        if (temp->left)
        {
            q.push(temp->left);
        }
    }

    while (!s.empty())
    {
        node *temp1 = s.top();
        cout << temp1->data << " ";
        s.pop();
    }
}

void reverseLevelOrderTraversalWithDesign(node *root)
{

    queue<node *> q;
    stack<node *> s;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();
        s.push(temp);

        if (temp == NULL)
        {
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {

            if (temp->right)
            {
                q.push(temp->right);
            }

            if (temp->left)
            {
                q.push(temp->left);
            }
        }
    }

    while (!s.empty())
    {
        node *temp1 = s.top();
        s.pop();

        if (temp1 == NULL)
        {
            cout << endl;
        }
        else
        {
            cout << temp1->data << " ";
        }
    }
}

// Here NULL will be used as a separator
// Whenever you come across NULL, it means that one of the levels is completed and you need to go to next line

void levelOrderTraversalWithDesign(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {

            cout << temp->data << " ";

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
}

int main()
{
    // Write C++ code here

    node *root = NULL;
    root = buildTree(root);

    cout << "Without Design" << endl;
    levelOrderTraversal(root);

    cout << endl;

    cout << "With Design" << endl;
    levelOrderTraversalWithDesign(root);

    cout << endl;

    cout << " Reverse Level Order Traversal" << endl;
    reverseLevelOrderTraversal(root);

    cout << endl;

    cout << "Reverse Level Order Traversal With Design: " << endl;
    reverseLevelOrderTraversalWithDesign(root);

    return 0;
}

// input
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
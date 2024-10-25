/*

- https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1
- https://gist.github.com/vedantbothikar/7daa1c62d462dc04a986ba647f7e3fb5

*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    
    /*
    We will check if anytime when we encounter a NULL,
    then rest all the elements should also be NULL
    This will make sure that the tree is complete binary
    which means except the last level, all are full
    and on the last level, the elements are filled 
    starting from the far left
    */
    bool isCompleteBinaryTree(struct Node* root) {
        
        // level order traversal
        
        // base case
        if(root == NULL) return true;
        
        queue<Node*> q;
        q.push(root);
        
        bool nullEncountered = false;
        
        while(!q.empty()) {
            
            Node* curr = q.front();
            q.pop();
            
            
            if(curr == NULL) {
                nullEncountered = true;
            }
            else {
                
                // check if despite NULL encountered, there are elements that are non-NULL
                if(nullEncountered) {
                    return false;
                }
                
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        
        
        return true;
    }
    
    /*
    This means that we need to check if every element is greater
    than the children of their
    And this property should be maintained everywhere
    
    Here we also assume that the tree is already Complete Binary Tree,
    since this check will be made after check if the tree is 
    CBT or not
    
    The left child of any element is at 2*+1
    Right child is at 2*i + 2
    */
    bool isHeapOrder(Node* root) {
        
        // base case: when root == NULL
        if(root == NULL) return true;
        
        Node* left = root->left;
        Node* right = root->right;
        
        // check if left is NOT NULL and less than the root
        // But if it is greater than root's data, then return false
        if(left != NULL and left->data > root->data) {
            // false since left is greater than root
            return false;
        }
        
        // check if right is NOT NULL and less than the root
        // But if it is greater than root's data, then return false
        if(right != NULL and right->data > root->data) {
            // false since right is greater than root
            return false;
        }
        
        // now continue checking for the left and right subtrees
        return isHeapOrder(left) && isHeapOrder(right);
    }
    
    
  public:
    bool isHeap(struct Node* tree) {
        // code here
        
        // REMEMBER: 
        // Heap = CompleteBinaryTree + HeapProperty
        
        // to check if a tree is a heap, we first need to check if the tree is complete binary tree 
        // and then need to check if the tree follows the heap property everywhere
        // HEAP PROPERTY: It means that every root node must be greater than the children
        
        
        if(isCompleteBinaryTree(tree) and isHeapOrder(tree)) return true;
        
        return false;
    }
};
// easier to read solution
void inorder(BinaryTreeNode<int> *root) {

    // base
    if(root == NULL) return;

    // swapping
    BinaryTreeNode<int>* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // traverse
    inorder(root->left);
    inorder(root->right);
}

void mirrorTree(BinaryTreeNode<int> *root) {
    // Write your code here.

    inorder(root);
}
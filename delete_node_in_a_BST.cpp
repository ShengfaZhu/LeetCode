// Delete Node in a BST
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) return NULL;
    if (root->val > key) {
        root->left = deleteNode(root->left, key);
    }
    else if (root->val < key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == NULL) return root->right;
        if (root->right == NULL) return root->left;
        TreeNode* min = findMin(root->right);
        root->val = min->val;
        root->right = deleteNode(root->right, min->val);
    }
    return root;
}

TreeNode* findMin(TreeNode* root) {
    assert(root != NULL);
    TreeNode* curr = root;
    while (curr->left) curr = curr->left;
    return curr;
}
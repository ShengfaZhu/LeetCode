// 222. Count Complete Tree Nodes
int countNodes(TreeNode* root) {
    if (root == NULL) return 0;
    // optimization, determine if full binary tree
    TreeNode *left = root, *right = root;
    int height = 0;
    while (right != NULL) {
        left = left->left;
        right = right->right;
        height++;
    }
    if (left == NULL)
        return (1 << height) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
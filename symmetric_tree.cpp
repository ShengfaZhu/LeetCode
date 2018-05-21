// Given a binary tree, check whether it is a 
// mirror of itself (ie, symmetric around its center).
// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool is_symm(TreeNode *p, TreeNode *q) {
    if (p == NULL && q == NULL) return true;
    if ((p != NULL && q == NULL) || (p == NULL && q != NULL)) return false;
    if (p->val != q->val) return false;
    else return is_symm(p->left, q->right) && is_symm(p->right, q->left);
}

bool isSymmetric(TreeNode* root) {
    if (root == NULL) return true;
    else return is_symm(root->left, root->right);
}
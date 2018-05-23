// Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along 
// the shortest path from the root node down to 
// the nearest leaf node.
// Note: A leaf is a node with no children.
// Example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <limits.h>
#define null NULL
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    int left_depth = root->left ? minDepth(root->left) : INT_MAX;
    int right_depth = root->right ? minDepth(root->right) : INT_MAX;
    return min(left_depth, right_depth) + 1;
}
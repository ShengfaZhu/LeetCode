// Given a binary tree, return the bottom-up level order traversal 
// of its nodes' values. (ie, from left to right, level by level from leaf to root).
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its bottom-up level order traversal as:
// [
//   [15,7],
//   [9,20],
//   [3]
// ]
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == NULL) return ans;
    queue<TreeNode*> q;// assisted queue
    q.push(root);
    TreeNode *curr;
    while(!q.empty()) {
        int sz = q.size();
        vector<int> tmp(sz, 0);
        for (int i = 0; i < sz; i++) {
            curr = q.front();
            q.pop();
            tmp[i] = curr->val;;
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        ans.push_back(tmp);
    }
    // reverse
    vector<vector<int>> ans_rev;
    for (int i = ans.size() - 1; i >= 0; i--)
        ans_rev.push_back(ans[i]);
    return ans_rev;
}
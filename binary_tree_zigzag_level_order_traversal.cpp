// Given a binary tree, return the zigzag level order traversal 
// of its nodes' values. (ie, from left to right, then right 
// to left for the next level and alternate between).
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
// ]
#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == NULL) return ans;
    queue<TreeNode*> q;
    queue<int> level;
    q.push(root);
    bool left2right = true;
    while(!q.empty()) {
        int sz = q.size();
        vector<int> row(sz);
        for (int i = 0; i < sz; i++) {
            TreeNode *curr = q.front();
            q.pop();
            int index = left2right ? i : sz - i - 1;
            row.at(index) = curr->val;
            if (curr->left) {
                q.push(curr->left), level.push(curr_l + 1);
            }
            if (curr->right) {
                q.push(curr->right), level.push(curr_l + 1);
            }
        }
        left2right = !left2right;
        ans.push_back](row);
    }  
    return ans;
}  
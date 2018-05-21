// Given a binary tree, return the level order traversal of 
// its nodes' values. (ie, from left to right, level by level).
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
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

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == NULL) return ans;
    queue<TreeNode*> q;
    queue<int> level;
    q.push(root);
    level.push(0);
    while(!q.empty()) {
        TreeNode *curr = q.front();
        cout << curr->val << "\t";
        q.pop();
        int curr_l = level.front();
        level.pop();
        if (curr_l == ans.size()) {
            vector<int> tmp = {curr->val};
            ans.push_back(tmp);
        }
        else {
            ans[curr_l].push_back(curr->val);
        }
        
        if (curr->left) {
            q.push(curr->left), level.push(curr_l + 1);
        }
        if (curr->right) {
            q.push(curr->right), level.push(curr_l + 1);
        }
    }  
    return ans;
    }
}
// Given a binary tree and a sum, determine if the tree 
// has a root-to-leaf path such that adding up all the 
// values along the path equals the given sum.
// Note: A leaf is a node with no children.
// Example:
// Given the below binary tree and sum = 22,
//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \      \
// 7    2      1
// return true, as there exist a root-to-leaf 
// path 5->4->11->2 which sum is 22.
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#define null NULL
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// generate binary based on level order traversal
TreeNode *generate_binary_tree(const vector<int>& nums) 
{
    if (nums.empty())
        return NULL;
    queue<TreeNode*> q;// assist queue
    TreeNode *root = new TreeNode(nums.at(0));
    q.push(root);
    int i = 1;
    while(!q.empty() && i < nums.size())
    {
        TreeNode *tmp = q.front();
        q.pop();
        if (i < nums.size() && nums[i] != NULL) {
            tmp->left = new TreeNode(nums[i]);
            q.push(tmp->left);
        }
        i++;
        if (i < nums.size() && nums[i] != NULL){
            tmp->right = new TreeNode(nums[i]);
            q.push(tmp->right);
        }
        i++;
    }
    return root;
}

bool hasPathSum(TreeNode* root, int sum) {
    if (root == NULL) return false;
    stack<TreeNode*> node;
    stack<int> total;
    node.push(root);
    total.push(root->val);
    while(!node.empty()) {
        TreeNode *curr = node.top();
        node.pop();
        int curr_sum = total.top();
        total.pop();
        if (curr->left == NULL && curr->right == NULL && curr_sum == sum) 
            return true;
        if (curr->right) {
            node.push(curr->right);
            total.push(curr_sum + curr->right->val);
        }
        if (curr->left) {
            node.push(curr->left);
            total.push(curr_sum + curr->left->val);
        }
    }
    return false;
}

void backtrack(vector<vector<int>>& res, vector<int> local, 
    TreeNode* root, int& sum) {
    if (root == NULL) return;
    local.push_back(root->val);
    if (root->left == NULL && root->right == NULL) {
        int tmp_sum = 0;
        for (int i = 0; i < local.size(); i++) tmp_sum += local[i];
        if (tmp_sum == sum){
            res.push_back(local);
        }
        return;
    }
    backtrack(res, local, root->left, sum);
    backtrack(res, local, root->right, sum);
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> res;
    vector<int> local;
    backtrack(res, local, root, sum);
    return res;
}

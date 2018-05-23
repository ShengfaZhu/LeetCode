// Given preorder and inorder traversal of a tree, construct the binary tree.
// Note:
// You may assume that duplicates do not exist in the tree.
// For example, given
// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
// Return the following binary tree:
//     3
//    / \
//   9  20
//     /  \
//    15   7
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

void level_traversal(TreeNode* root) {
    if (root == NULL) return;
    queue<TreeNode*> q;// assisted queue
    q.push(root);
    TreeNode *curr;
    while(!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            curr = q.front();
            q.pop();
            cout << curr->val << "\t";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << endl;
    }
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, 
    int pre_s, int pre_e, int in_s, int in_e) {
    if (pre_s == pre_e && in_s == in_e) {
        TreeNode *tmp = new TreeNode(preorder[pre_s]);
        return tmp;
    }
    if (pre_s > pre_e || in_s > in_e) return NULL;
    int i = in_s;
    while(i <= in_e) {
        if (inorder[i] == preorder[pre_s]) break;
        i++;
    }
    TreeNode *root = new TreeNode(preorder[pre_s]);
    root->left = buildTree(preorder, inorder, pre_s + 1, pre_s + i - in_s, in_s, i - 1);
    root->right = buildTree(preorder, inorder, pre_s + i - in_s + 1, pre_e, i + 1, in_e);
    return root;
} 

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

int main() {
    vector<int> preorder = {3,9,20,15,7}, inorder = {9,3,15,20,7};
    TreeNode *root = buildTree(preorder, inorder);
    level_traversal(root);
    system("pause");
    return 0;
}
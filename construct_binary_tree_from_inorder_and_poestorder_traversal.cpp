// Given inorder and postorder traversal of a tree, 
// construct the binary tree.
// Note:
// You may assume that duplicates do not exist in the tree.
// For example, given
// inorder = [9,3,15,20,7]
// postorder = [9,15,7,20,3]
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

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder,
    int in_s, int in_e, int post_s, int post_e) {
    if (in_s == in_e && post_s == post_e) {
        TreeNode *tmp = new TreeNode(inorder[in_s]);
        return tmp;
    }
    if (post_s > post_e || in_s > in_e) return NULL;
    int i = in_s;
    while(i <= in_e) {// track down root
        if (inorder[i] == postorder[post_e]) break;
        i++;
    }
    TreeNode *root = new TreeNode(postorder[post_e]);
    root->left = buildTree(inorder, postorder, in_s, i - 1, post_s, post_s + i - in_s - 1);
    root->right = buildTree(inorder, postorder, i + 1, in_e, post_s + i - in_s, post_e - 1);
    return root;
} 

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return buildTree(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
}

int main() {
    vector<int> inorder = {9,3,15,20,7}, postorder = {9,15,7,20,3};
    TreeNode *root = buildTree(inorder, postorder);
    level_traversal(root);
    system("pause");
    return 0;
}
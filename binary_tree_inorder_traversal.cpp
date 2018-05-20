// Given a binary tree, return the inorder traversal of its nodes' values.
// Example:
// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3
// Output: [1,3,2]
// Follow up: Recursive solution is trivial, could you do it iteratively?

#include <iostream>
#include <limits.h>
#include <vector>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *binaryTreeGenerate(vector<int> v)
{
	static int pos = -1;
	pos++;
	if (v.empty()) return NULL;
	TreeNode *t = new TreeNode(NULL);
	if (v[pos] == INT_MAX) return NULL;
	else
	{
		t->val = v[pos];
		t->left = binaryTreeGenerate(v);
		t->right = binaryTreeGenerate(v);
	}
	return t;
}

// void preorder_traversal(TreeNode *head) {
//     if (head == NULL) return;
//     cout << head->val << "\t";
//     preorder_traversal(head->left);
//     preorder_traversal(head->right);
// }

// void inorder_traversal(TreeNode *head) {
//     if (head == NULL) return;
//     inorder_traversal(head->left);
//     cout << head->val << "\t";
//     inorder_traversal(head->right);
// }


// void postorder_traversal(TreeNode *head) {
//     if (head == NULL) return;
//     postorder_traversal(head->left);
//     postorder_traversal(head->right);
//     cout << head->val << "\t";
// }

void goAlongLeftBranch(TreeNode* x, stack<TreeNode*>& s)
{
    while(x) 
    {
        s.push(x);
        x = x->left;
    }
}

vector<int> inorderTraversal(TreeNode* root) 
{
    vector<int> ans;
    stack<TreeNode*> s;
    while(true) {
        goAlongLeftBranch(root, s);
        if(s.empty()) break;
        root = s.top();
        s.pop();
        ans.push_back(root->val);
        root = root->right;
    }
    return ans;
}

int main() {
    vector<int> nums = {5, 3, 1, INT_MAX, INT_MAX, 4, 
        INT_MAX, INT_MAX, 7, 6, INT_MAX, INT_MAX, 8, 
        INT_MAX, INT_MAX};
    TreeNode *head = binaryTreeGenerate(nums);
    vector<int> ans = inorderTraversal(head);
    for(int& i : ans) cout << i << "\t";
    system("pause");
    return 0;
}
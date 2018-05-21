// Given a binary tree, determine if it is a valid binary search tree (BST).
// Assume a BST is defined as follows:
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

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

bool isValidBST(TreeNode* root) {
    vector<int> ans = inorderTraversal(root);
    for (int i = 1; i < ans.size(); i++) {
        if (ans[i] <= ans[i - 1])
            return false;
    }
    return true;    
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
// Given a binary tree, find its maximum depth.
// The maximum depth is the number of nodes along 
// the longest path from the root node down to the farthest leaf node.
// Note: A leaf is a node with no children.
// Example:
// Given binary tree [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its depth = 3.
#include <iostream>
#include <queue>
#include <vector>
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

int maxDepth(TreeNode* root) {
    int depth = 0;
    if (root == NULL) return depth;
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
        depth++;
    }
    return depth;
}

int main() {
    vector<int> nums = {0,2,4,1,null,3,-1,5,1,null,6,null,8};
    TreeNode *root = generate_binary_tree(nums);
    cout << "maximun depth of binary tree is " << maxDepth(root) << endl;
    system("pause");
    return 0;
}
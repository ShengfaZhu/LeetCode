// Given an array where elements are sorted in ascending order, 
// convert it to a height balanced BST.
// For this problem, a height-balanced binary tree is defined 
// as a binary tree in which the depth of the two subtrees of 
// every node never differ by more than 1.
// Example:
// Given the sorted array: [-10,-3,0,5,9],
// One possible answer is: [0,-3,9,-10,null,5], which represents 
// the following height balanced BST:
//       0
//      / \
//    -3   9
//    /   /
//  -10  5
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

TreeNode* sortedArrayToBST(vector<int>& nums, int low, int high) {
    if (low == high) {
        TreeNode *tmp = new TreeNode(nums[low]);
        return tmp;
    }
    if (low > high) return NULL;
    int mid = low + (high - low) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(nums, low, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, high);
    return root;
} 

TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.empty()) return NULL;
    return sortedArrayToBST(nums, 0, nums.size()-1);
}

int main() {
    vector<int> nums = {-10,-3,0,5,9};
    TreeNode* root = sortedArrayToBST(nums);
    level_traversal(root);
    system("pause");
    return 0;
}
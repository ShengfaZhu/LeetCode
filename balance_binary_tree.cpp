// Given a binary tree, determine if it is height-balanced.
// For this problem, a height-balanced binary tree is defined as:
// a binary tree in which the depth of the two subtrees 
// of every node never differ by more than 1.
// Example 1:
// Given the following tree [3,9,20,null,null,15,7]:

//     3
//    / \
//   9  20
//     /  \
//    15   7
// Return true.
#include <iostream>
#include <vector>
#include <queue>
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

// O(n^2) solution
// int height(TreeNode* root) {
//     if (root == NULL) return 0;
//     return max(height(root->left), height(root->right)) + 1;
// }

// bool isBalanced(TreeNode* root) {
//     // calculate height
//     if (root == NULL) return true;
//     return abs(height(root->left) - height(root->right)) <= 1 
//         && isBalanced(root->left) && isBalanced(root->right);
// }


// O(n) solution
int height(TreeNode *root) {
    if (root == NULL) return 0;
    int left = height(root->left);
    if (left == -1) return -1;
    int right = height(root->right);
    if (right == -1) return -1;
    if (abs(left - right) > 1) return -1;
    return max(left, right) + 1;
}

bool isBalanced(TreeNode* root) {
    return height(root) != -1;
}


int main() {
    vector<int> nums = {3,9,20,null,null,15,7};
    TreeNode* root = generate_binary_tree(nums);
    cout << isBalanced(root) << endl;
    system("pause");
    return 0; 
}


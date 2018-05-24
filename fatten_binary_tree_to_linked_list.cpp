// Given a binary tree, flatten it to a linked list in-place.
// For example, given the following tree:

//     1
//    / \
//   2   5
//  / \   \
// 3   4   6
// The flattened tree should look like:
// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6
#include <iostream>
#include <stack>
#include <queue>
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

void flatten(TreeNode* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return;
    flatten(root->left);
    flatten(root->right);
    if (root->left != NULL) {
        TreeNode *p = root->left;
        while(p->right) p = p->right;
        p->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
}

int main() {
    vector<int> nums = {1, 2, 5, 3, 4, null, 6};
    TreeNode *root = generate_binary_tree(nums);
    flatten(root);
    level_traversal(root);
    system("pause");
    return 0;
}
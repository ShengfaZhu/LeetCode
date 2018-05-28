// Given a binary tree containing digits from 0-9 only, 
// each root-to-leaf path could represent a number.
// An example is the root-to-leaf path 1->2->3 which represents the number 123.
// Find the total sum of all root-to-leaf numbers.
// Note: A leaf is a node with no children.
// Example:
// Input: [1,2,3]
//     1
//    / \
//   2   3
// Output: 25
// Explanation:
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
// Therefore, sum = 12 + 13 = 25.
int sumNumbers(TreeNode* root) {
    if(root == NULL) return 0;
    int total_sum = 0;
    queue<TreeNode*> q;
    q.push(root);
    queue<int> sum;
    sum.push(root->val);
    while(!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        int curr_sum = sum.front();
        sum.pop();
        if (curr->left == NULL && curr->right == NULL) total_sum += curr_sum;
        if (curr->left) {
            q.push(curr->left);
            sum.push(curr->left->val + curr_sum * 10);
        }
        if(curr->right) {
            q.push(curr->right);
            sum.push(curr->right->val + curr_sum * 10);
        }
    }
    return total_sum;
}
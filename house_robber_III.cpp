// 337. House Robber III
// two conditions for dynamic programming: 
// "optimal substructure" + "overlapping of subproblems"
int rob(TreeNode* root) {    
    vector<int> res = robsub(root);
    return max(res[0], res[1]);
}

vector<int> robsub(TreeNode* root) {
    vector<int> ans(2, 0);
    if (root == NULL) return ans;
    vector<int> ans_left = robsub(root->left), ans_right = robsub(root->right);
    ans[0] = max(ans_left[0], ans_left[1]) + max(ans_right[0], ans_right[1]);
    ans[1] = root->val + ans_left[0] + ans_right[0];
    return ans;
}
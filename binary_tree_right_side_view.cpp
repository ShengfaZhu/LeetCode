// 199. Binary Tree Right Side View
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if (root == NULL) return ans;
    queue<TreeNode*> st;
    st.push(root);
    while(!st.empty()) {
        int sz = st.size();
        while (sz--) {
            TreeNode *curr = st.front();
            st.pop();
            if (sz == 0)
                ans.push_back(curr->val);
            if (curr->left) st.push(curr->left);
            if (curr->right) st.push(curr->right);
        }
    }
    return ans;
}
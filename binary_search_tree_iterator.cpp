// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode *root) {
        // 将左侧的所有节点入栈
        while (root != NULL) {
            st.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (st.empty()) return false;
        else return true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *curr = st.top();
        st.pop();
        if (curr->right) {
            TreeNode *right_root = curr->right;
            // 将右子树的所有左节点入栈
            while (right_root) {
                st.push(right_root);
                right_root = right_root->left;
            }
        }
        return curr->val;
    }
};
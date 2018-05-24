// Example:
// Given the following perfect binary tree,
//      1
//    /  \
//   2    3
//  / \  / \
// 4  5  6  7
// After calling your function, the tree should look like:
//      1 -> NULL
//    /  \
//   2 -> 3 -> NULL
//  / \  / \
// 4->5->6->7 -> NULL

// Definition for binary tree with next pointer.
struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
void connect(TreeLinkNode *root) {
    if (root == NULL) return;
    TreeLinkNode *pre = root, *curr = NULL;
    while(pre->left) {
        curr = pre;
        curr->left->next = curr->right;
        while(curr->next) {
            curr->right->next = curr->next->left;
            curr = curr->next;
            curr->left->next = curr->right;
        }
        pre = pre->left;
    }
}
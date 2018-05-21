// Given an integer n, generate all structurally unique 
// BST's (binary search trees) that store values 1 ... n.
// Example:
// Input: 3
// Output:
// [
//   [1,null,3,2],
//   [3,2,null,1],
//   [3,1,null,null,2],
//   [2,1,3],
//   [1,null,2,null,3]
// ]
// Explanation:
// The above output corresponds to the 5 unique BST's shown below:

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#define null NULL
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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


void goAlongLeftBranch(TreeNode* x, stack<TreeNode*>& s)
{
    while(x) 
    {
        s.push(x);
        x = x->left;
    }
}

void inorderTraversal(TreeNode* root) 
{
    stack<TreeNode*> s;
    while(true) {
        goAlongLeftBranch(root, s);
        if(s.empty()) break;
        root = s.top();
        s.pop();
        cout << root->val << "\t";
        root = root->right;
    }
}


TreeNode* clone(TreeNode* root){
    if(root == nullptr)
        return nullptr;
    TreeNode* newroot = new TreeNode(root->val);
    newroot->left = clone(root->left);
    newroot->right = clone(root->right);
    return newroot;
}

TreeNode *insrt_treenode(TreeNode *root, int value) {
    if (root == NULL) {
        root = new TreeNode(value);
        return root;
    }
    TreeNode *p = root, *hot;
    while(p) {
        hot = p;
        if (hot->val > value) p = hot->left;
        else p = hot->right;
    }
    hot->val > value ? hot->left = new TreeNode(value) : hot->right = new TreeNode(value);
    return root;
}

vector<TreeNode*> gen_trees(int start, int end) {
    vector<TreeNode*> ans;
    if (start > end) {
        ans.push_back(NULL);
        return ans;
    }
    if (start == end) {
        ans.push_back(new TreeNode(start));
        return ans;
    }
    for (int i = start; i <= end; i++) {
        vector<TreeNode*> left_tree = gen_trees(start, i - 1);
        vector<TreeNode*> right_tree = gen_trees(i + 1, end);
        for (auto lnode : left_tree){
            for (auto rnode : right_tree){
                TreeNode *root = new TreeNode(i);
                root->left = lnode;
                root->right = rnode;
                ans.push_back(root);
            }
        }
    }
    return ans;
}

vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> ans;
    if (n == 0)
        return ans;
    return gen_trees(1, n);
}

int main() 
{
    int n = 3;
    vector<TreeNode*> res = generateTrees(n);
    cout << "size : " << res.size() << endl;
    for(int i = 0; i < res.size(); i++) {
        inorderTraversal(res[i]);
        cout << endl;
    }
    system("pause");
    return 0;
}
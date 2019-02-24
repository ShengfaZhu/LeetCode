# 二叉树算法(Binary tree)

# 1 二叉树的遍历
二叉树的遍历有前序遍历、中序遍历、后序遍历和层次遍历等方法，其中前、中和后序遍历的递归方法较好实现。二叉树的遍历方法是基础。

# 1.1 先序遍历
顺序：根节点->左节点->右节点.
```c++
void preOrder(const TreeNode* root, vector<int>* res) {
    if (root == nullptr) return;
    res->push_back(root->val);
    preOrder(root->left, res);
    preOrder(root->right, res);
}
```

# 1.2 先序遍历(循环)
顺序：根节点->左节点->右节点.
```c++
void preOrderIterative(TreeNode* root, vector<int>* res) {
    if (root == nullptr) return;
    stack<TreeNode* > st;
    st.push(root);
    while(!st.empty()) {
        TreeNode* curr = st.top();
        st.pop();
        while(curr) {
            res->push_back(curr->val);
            if (curr->right) st.push(curr->right);
            curr = curr->left;
        }
    }
}
```


# 1.3 中序遍历
顺序：左节点->根节点->右节点.
```c++
void inOrder(const TreeNode* root, vector<int>* res) {
    if (root == nullptr) return;
    inOrder(root->left, res);
    res->push_back(root->val);
    inOrder(root->right, res);
}
```
# 1.4 中序遍历（循环）
思路：将树的左枝依次存入stack中，然后顺序弹出，并将弹出节点的左枝存在stack中。
```c++
void goAlongLeftBranch(TreeNode* root, stack<TreeNode*>* s) {
    while (root) {
        s->push(root);
        root = root->left;
    }
}

void inorderIterative(TreeNode* root, vector<int>* res) {
    if (root == nullptr) return;
    stack<TreeNode*> s;
    goAlongLeftBranch(root, &s);
    while(!s.empty()){
        TreeNode* curr = s.top();
        s.pop();
        res->push_back(curr->val);
        if (curr->right) goAlongLeftBranch(curr->right, &s);
    }
}
```
# 1.5 后序遍历
顺序：左节点->右节点->根节点.
```c++
void postOrder(const TreeNode* root, vector<int>* res) {
    if (root == nullptr) return;
    postOrder(root->left, res);
    postOrder(root->right, res);
    res->push_back(root->val);
}
```
# 1.6 层次遍历
从二叉树的根节点开始，分层对二叉树进行遍历，将其打印出来。
```c++
void level(TreeNode* root) {
    if (root == nullptr) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        while(sz--){
            TreeNode* curr = q.front();
            q.pop();
            cout << curr->val << "\t";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << endl;
    }
}
```
二叉树的层次遍历相当于宽度优先遍历，可以用来求二叉树的最大深度。

# 2 二叉树的结构

## 2.1 相同树的判断

用递归进行实现，先判断根节点是否相同，然后再判断左子树和右子树是否相同。
```c++
bool isSameTree(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr && root2 == nullptr) return true;
    else if ((root1 == nullptr && root2 != nullptr) || (root1 != nullptr && root2 == nullptr)
        return false;
    else if (root1->val != root2->val) return false;
    else return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
}
```

## 2.2 对称树的判断

```c++
bool isSymHelp(TreeNode* p, TreeNode* q) {
    if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)) return false;
    else if (p == nullptr && q == nullptr) return true;
    else if (p->val != q->val) return false;
    else return isSymHelp(p->left, q->right) && isSymHelp(p->right, q->left);
}

bool isSymmetric(TreeNode* root) {
    if (root == nullptr) return true;
    else return isSymHelp(root->left, root->right);
}
```

## 2.3 平衡树的判断
平衡二叉树的定义是任何节点的左右子树的高度相差不超过1。
容易相当的方法，就是计算所有节点的左右子树高，判断其相差是否会超过1.
```c++
int depth (TreeNode *root) {
    if (root == NULL) return 0;
    return max (depth(root -> left), depth (root -> right)) + 1;
}

bool isBalanced (TreeNode *root) {
    if (root == NULL) return true;
    int left=depth(root->left);
    int right=depth(root->right);
    return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}
```
上述的算法时间复杂度显然是$O(N^{2})$的。

可以采用深度优先**DFS**的方法，在进行深度优先搜索的同时，判断树高是否相差超过1，若超过1，则返回一个负值，若不超过则返回真实的树高。这样的算法复杂度是$O(N)$的。
```c++
int dfsHeight (TreeNode *root) {
    if (root == NULL) return 0;
    
    int leftHeight = dfsHeight (root -> left);
    if (leftHeight == -1) return -1;
    int rightHeight = dfsHeight (root -> right);
    if (rightHeight == -1) return -1;
    
    if (abs(leftHeight - rightHeight) > 1)  return -1;
    return max (leftHeight, rightHeight) + 1;
}
bool isBalanced(TreeNode *root) {
    return dfsHeight (root) != -1;
}
```

## 2.4 计算树的直径
计算树的直径可以计算每个节点的树高，然后比较，然是显然是$O(N^2)$的时间复杂度。下面的解法可以在$O(N)$的时间计算树的直径，其实也是深度优先搜索。
```c++
public class Solution {
    int max_d = 0;
    
    public int diameterOfBinaryTree(TreeNode root) {
        maxDepth(root);
        return max;
    }
    
    private int maxDepth(TreeNode root) {
        if (root == nullptr) return 0;
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        max_d = max(max_d, left + right);
        
        return max(left, right) + 1;
    }
}
```

## 最低共同祖先LCA
假设二叉树(不一定是平衡二叉树)中节点的值各不相同，找出两个节点的最低共同祖先。
```c++
TreeNode * dfsTraverse(TreeNode * root, TreeNode * p , TreeNode * q)
{
    if( root == p || root == q || root == NULL)
        return root;
    TreeNode * parent1 = dfsTraverse(root->left, p, q);
    TreeNode * parent2 = dfsTraverse(root->right, p, q);
    if( parent1 && parent2)
        return root;
    else
        return parent1 ? parent1 : parent2;
}
TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q)
{
    return dfsTraverse(root, p, q);
}
```
是DFS的做法，返回值为NULL，说明在以该节点为根节点的子树中，并不包含p和q；若返回值不为NULL，说明该节点为根节点的子树中至少有q或p。因此，若左右子树都返回不是NULL，则LCA就是根节点，若左右子树只有一个返回不是NULL，则LCA为不是NULL的返回节点。

# 3 建树
建树一般采用递归的方法，先确定根节点，然后确定根节点的左、右节点。

## 3.1 数组建树
给定一个递增的线性数组，将其建立为平衡二叉搜索树。
```c++
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
```


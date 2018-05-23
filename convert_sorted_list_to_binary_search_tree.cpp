// Given a singly linked list where elements are 
// sorted in ascending order, convert it to a height balanced BST.
// For this problem, a height-balanced binary tree is defined as 
// a binary tree in which the depth of the two subtrees of every 
// node never differ by more than 1.
// Example:
// Given the sorted linked list: [-10,-3,0,5,9],
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

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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

TreeNode *sortedListToBST(ListNode* head, ListNode* tail) {
    if (head == tail) return NULL;
    ListNode *slow = head, *fast = head;
    while(fast != tail && fast->next != tail){
        fast = fast->next->next;
        slow = slow->next;
    }
    TreeNode *root = new TreeNode(slow->val);
    root->left = sortedListToBST(head, slow);
    root->right = sortedListToBST(slow->next, tail);
    return root;
}


TreeNode* sortedListToBST(ListNode* head) {
    if (head == NULL) return NULL;
    return sortedListToBST(head, NULL);
}

int main() {
    vector<int> nums = {-10,-3,0,5,9};
    ListNode *head = new ListNode(nums[0]), *p = head;
    for (int i = 1; i < 5; i++)
    {
        ListNode *tmp = new ListNode(nums[i]);
        p->next = tmp;
        p = p->next;
    }
    TreeNode* root = sortedListToBST(head);
    level_traversal(root);
    system("pause");
    return 0;
}
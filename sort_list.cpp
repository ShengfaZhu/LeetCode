// Sort a linked list using insertion sort.Sort a linked 
// list in O(n log n) time using constant space complexity.
#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* merge(ListNode* left, ListNode* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;
    ListNode *head = new ListNode(0);
    ListNode *l = left, *r = right, *p = head;
    while(l != NULL && r != NULL) {
        if (l->val < r->val){
            p->next = l;
            l = l->next;
        } 
        else {
            p->next = r;
            r = r->next;
        }
        p = p->next;
    }
    if (r != NULL) p->next = r;
    if (l != NULL) p->next = l;
    return head->next;
}

ListNode* sortList(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode *slow = head, *fast = head, *pre;
    while(fast && fast->next) {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = NULL;
    ListNode* ans_left = sortList(head), *ans_right = sortList(slow);
    return merge(ans_left, ans_right);
}

int main() {
    vector<int> num1 = {-1, 5, 3, 4, 0};
    ListNode *head1 = new ListNode(num1[0]), *p = head1;
    for (int i = 1; i < num1.size(); i++) {
        ListNode *tmp = new ListNode(num1[i]);
        p->next = tmp;
        p = p ->next;
    }
    ListNode *h1 = sortList(head1);
    p = h1;
    while (p) {
        cout << p->val << "\t";
        p = p->next;
    }
    system("pause");
    return 0;
}
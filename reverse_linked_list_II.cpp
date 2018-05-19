// Reverse a linked list from position m to n. Do it in one-pass.
// Note: 1 ≤ m ≤ n ≤ length of list.
// Example:
// Input: 1->2->3->4->5->NULL, m = 2, n = 4
// Output: 1->4->3->2->5->NULL

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode pre_head(0);
    pre_head.next = head;
    ListNode *pre = &pre_head;
    n = n - m;
    while(--m) pre = pre->next;
    ListNode *rev = pre->next;
    while(n--) {
        ListNode *tmp = rev->next;
        rev->next = tmp->next;
        tmp->next = pre->next;
        pre->next = tmp;    
    }
    return pre_head.next;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    ListNode *head = new ListNode(a[0]), *p = head;
    for (int i = 1; i < 5; i++) {
        ListNode *tmp = new ListNode(a[i]);
        p->next = tmp;
        p = p->next;
    }
    ListNode *res = reverseBetween(head, 2, 4);
    p = res;
    while(p) {
        cout << p->val << "\t";
        p = p->next;
    }
    system("pause");
    return 0;
}

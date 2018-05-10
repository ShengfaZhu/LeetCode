// Given a linked list, remove the n-th node from 
// the end of list and return its head.
// Example:
// Given linked list: 1->2->3->4->5, and n = 2.
// After removing the second node from the end, the linked list becomes 1->2->3->5.
// Note:
// Given n will always be valid.
#include <iostream>
#include <vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == NULL) {
        return NULL;
    }
    ListNode *p = head;
    int i = 0;
    while (i < n) {
        p = p->next;
        i++;
    }
    if (p == NULL) {//remove head
        head = head->next;
        return head;
    }
    ListNode *q = head;
    p = p->next;
    while (p) {       
        q = q->next;
        p = p->next;
    }
    q->next = q->next->next;
    return head;
}

int main() {
    vector<int> a = {1, 2};
    ListNode *head = new ListNode(a[0]), *p = head;
    for (auto it = a.begin() + 1; it != a.end(); it++) {
        ListNode *tmp = new ListNode(*it);
        p->next = tmp;
        p = p->next;
    }
    int n = 2;
    ListNode *h2 = removeNthFromEnd(head, n);
    p = h2;
    while(p) {
        cout << p->val << "\t";
        p = p->next;
    }
    system("pause");
    return 0;
}
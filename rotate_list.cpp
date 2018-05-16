// Given a linked list, rotate the list to the 
// right by k places, where k is non-negative.
// Example 1:
// Input: 1->2->3->4->5->NULL, k = 2
// Output: 4->5->1->2->3->NULL
// Explanation:
// rotate 1 steps to the right: 5->1->2->3->4->NULL
// rotate 2 steps to the right: 4->5->1->2->3->NULL

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if (!head){
        return head;
    }
    // combine linklist to a circle
    int sz = 1;
    ListNode *p = head;
    while (p->next != NULL) {
        p = p->next;
        sz++;
    }
    p->next = head;
    // cut circle
    p = head;
    k = sz - (k % sz);
    int i = 1;
    while(i < k) {
        p = p->next;
        i++;
    }
    ListNode *h = p->next;
    p->next = NULL;
    return h;
}

int main() {
    int a[] = {0, 1, 2};
    ListNode *head = new ListNode(a[0]), *p = head;
    for(int i = 1; i < 3; i++) {
        ListNode *tmp = new ListNode(a[i]);
        p->next = tmp;
        p = p->next;
    }
    int k = 4;
    ListNode* res = rotateRight(head, k);
    p = res;
    while(p) {
        cout << p->val << "\t";
        p = p->next;
    }
    system("pause");
    return 0;
}
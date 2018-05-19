// Given a linked list and a value x, partition it such that all 
// nodes less than x come before nodes greater than or equal to x.
// You should preserve the original relative order of the nodes 
// in each of the two partitions.
// Example:
// Input: head = 1->4->3->2->5->2, x = 3
// Output: 1->2->2->4->3->5
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x) {
    if (head == NULL) return head;
    ListNode *great(NULL), *less(NULL), *p = head, *q_great(NULL), *q_less(NULL);
    while (p) {
        if (p->val >= x)
            if (great == NULL) {
                great = new ListNode(p->val);
                q_great = great;
            }
            else{
                q_great->next = new ListNode(p->val);
                q_great = q_great->next;
            }
        else 
            if (less == NULL) {
                less = new ListNode(p->val);
                q_less = less;
            }
            else {
                q_less->next = new ListNode(p->val);
                q_less = q_less->next;
            }
        p = p->next;
    }
    if (q_less == NULL)
        return great;
    q_less->next = great;
    return less;
}

int main() {
    int a[] = {1}, x = 0;
    ListNode *head = new ListNode(a[0]), *p = head;
    for (int i = 1; i < 1; i++) {
        ListNode *tmp = new ListNode(a[i]);
        p->next = tmp;
        p = p->next;
    };
    ListNode *res = partition(head, x);
    p = res;
    while(p) {
        cout << p->val << "\t";
        p = p->next;
    }
    system("pause");
    return 0;
}
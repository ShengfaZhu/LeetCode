// Given a sorted linked list, delete all duplicates 
// such that each element appear only once.
// Example 1:
// Input: 1->1->2
// Output: 1->2

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL)
        return head;
    int tmp = head->val;
    // determine head
    while(head->next) {
        if (head->next->val != tmp) break;
        else head = head->next;
    }
    if (head->next == NULL)
        return head;
    // remove following depulicates
    ListNode *p = head->next, *q = head;
    tmp = p->val;
    while(p) {
        if (p->next != NULL && p->next->val != tmp) {
            q->next = p;
            q = q->next;
            p = p->next;
            tmp = p->val;
        }
        else if (p->next == NULL) {
            q->next = p;
            break;
        }
        else
            p = p->next;
    }
    return head;
}

int main() {
    int a[] = {1, 2};
    ListNode *head = new ListNode(a[0]), *p = head;
    for (int i = 1; i < 2; i++) {
        ListNode *tmp = new ListNode(a[i]);
        p->next = tmp;
        p = p->next;
    }
    ListNode *res = deleteDuplicates(head);
    p = res;
    while(p) {
        cout << p->val << "\t";
        p = p->next;
    }
    system("pause");
    return 0;
}
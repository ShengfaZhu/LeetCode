// Given a sorted linked list, delete all nodes that 
// have duplicate numbers, leaving only distinct numbers 
// from the original list
// Example 1:
// Input: 1->2->3->3->4->4->5
// Output: 1->2->5
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
    int tmp = head->val, count = 0;
    while (head) {
        if (head->val != tmp) {
            tmp = head->val;
            count = 1;
        }
        else 
            count++;
        if ((head->next != NULL && count == 1 && head->next->val != tmp) 
            || (head->next == NULL && count == 1))
            break;
        head = head->next;
    }
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *q = head, *p = head->next;
    tmp = p->val, count = 0;
    while(p) {
        if (p->val != tmp) {
            tmp = p->val;
            count = 1;
        }
        else  
            count++;
        if ((p->next != NULL && count == 1 && p->next->val != tmp) || 
            (p->next == NULL && count == 1)) {
            q->next = p;
            q = q->next;
        }
        p = p->next;
    }
    q->next = NULL;
    return head;
}

int main() {
    int a[] = {1, 2, 2};
    ListNode *head = new ListNode(a[0]), *p = head;
    for (int i = 1; i < 3; i++) {
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
    return true;
}
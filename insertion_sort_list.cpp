// Sort a linked list using insertion sort.
#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertionSortList(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode *pre = head->next, *follow = head;
    while(pre) {
        ListNode *curr = pre;
        pre = pre->next;
        follow->next = pre;
        if (curr->val <= head->val) {
            curr->next = head;
            head = curr;
        }
        else if (curr->val >= follow->val) {
            curr->next = follow->next;
            follow->next = curr;
            follow = curr;
        }
        else {
            ListNode *p = head, *q = head->next;
            while(p != follow) {
                if (curr->val <= q->val) {
                    p->next = curr;
                    curr->next = q;
                    break;
                }
                p = q;
                q = q->next;
            }
        }
    }
    return head;
}

int main() {
    vector<int> num = {-1, 5, 3, 4, 0};
    ListNode *head = new ListNode(num[0]), *p = head;
    for (int i = 1; i < num.size(); i++) {
        ListNode *tmp = new ListNode(num[i]);
        p->next = tmp;
        p = p ->next;
    }
    ListNode *h = insertionSortList(head);
    p = h;
    while (p) {
        cout << p->val << "\t";
        p = p->next;
    }
    system("pause");
    return 0;
}
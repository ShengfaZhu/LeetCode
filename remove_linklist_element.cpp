// 203. Remove Linked List Elements
ListNode* removeElements(ListNode* head, int val) {
    if (head == NULL) return NULL;
    ListNode *p = head;
    while (p != NULL && p->val == val) {
        head = p->next;
        p = p->next;
    }
    if (p == NULL) return head;
    ListNode *q = p->next;
    while (q) {
        if (q->val == val) {
            p->next = q->next;
            q = q->next;
        }
        else {
            p = p->next;
            q = q->next;               
        }
    }
    return head;
}
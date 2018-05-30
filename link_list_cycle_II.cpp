// Given a linked list, return the node where the cycle begins. 
// If there is no cycle, return null.

Note: Do not modify the linked list.
ListNode *detectCycle(ListNode *head) {
    if (head == NULL || head->next == NULL) return NULL; 
    ListNode *slow = head, *fast = head;
    bool flag = true;
    while (flag || slow != fast) {
        if (fast == NULL || fast->next == NULL)// no cycle
            return NULL;
        flag = false;
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *p = head;
    while (p != slow) {
        p = p->next;
        slow = slow->next;
    }
    return p;
}
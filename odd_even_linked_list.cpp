    328. Odd Even Linked List
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* last_odd = head, *last_even = head->next, *p = head->next->next;
        while (p != NULL) {
            last_even->next = p->next;
            last_even = last_even->next;
            p->next = last_odd->next;
            last_odd->next = p;
            last_odd = last_odd->next;
            if (last_even) p = last_even->next;
            else break;
        }
        return head;
    }
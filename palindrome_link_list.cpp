// 234. Palindrome Linked List
bool isPalindrome(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    // reverse the second half
    if (fast != NULL) slow = slow->next;
    slow = reverse(slow);
    while (slow) {
        if (slow->val != head->val) return false;
        slow = slow->next;
        head = head->next;
    }
    return true;    
}

ListNode* reverse(ListNode* head) {
    if (head == NULL) return head;
    ListNode* p = head, *tmp;
    while (p->next) {
        tmp = p->next;
        p->next = tmp->next;
        tmp->next = head;
        head = tmp;
    }
    return head;
}
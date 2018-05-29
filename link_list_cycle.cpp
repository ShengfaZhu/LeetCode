// Given a linked list, determine if it has a cycle in it.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// two pointer method
bool hasCycle(ListNode *head) {
    if (head == NULL) return false;
    ListNode *slow = head, *fast = head->next;
    while (slow != fast) {
        if (fast == NULL || fast->next == NULL || fast->next->next == NULL) 
            return false;
        fast = fast->next->next;
        slow = slow->next;
    }
    return true;
}
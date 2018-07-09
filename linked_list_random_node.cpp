// 382. Linked List Random Node
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* p;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        p = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res = p->val, count = 1;
        ListNode* q = p->next;
        while (q) {
            count++;
            if (rand() % count == 0) 
                res = q->val;
            q = q->next;
        }
        return res;
    }
};
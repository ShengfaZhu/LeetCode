// Write a program to find the node at which the intersection 
// of two singly linked lists begins.
// For example, the following two linked lists:
// A:          a1 → a2
//                    ↘
//                      c1 → c2 → c3
//                    ↗            
// B:     b1 → b2 → b3
// begin to intersect at node c1.

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == NULL || headB == NULL) return NULL;
    ListNode *pA = headA, *pB = headB;
    int count = 0;
    while(pA != pB) 
    {
        if (count == 2) break;
        if (pA->next != NULL) pA = pA->next;
        else {
            if (count == 0) pA = headB;
            count++;   
        }
        if (pB->next != NULL) pB = pB->next;
        else {
            pB = headA;
        }
    }
    if (count < 2) return pA;
    return NULL;
}
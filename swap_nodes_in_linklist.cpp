// Given a linked list, swap every two adjacent nodes and return its head.
// Example:
// Given 1->2->3->4, you should return the list as 2->1->4->3.
// Note:
// Your algorithm should use only constant extra space.
// You may not modify the values in the list's nodes, 
// only nodes itself may be changed.
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(NULL) {} 
}; 

// iterative version
// ListNode* swapPairs(ListNode* head) {
//     if (head == NULL || head->next == NULL)
//         return head;
//     // swap head node and second node
//     ListNode *p1 = head->next;
//     head->next = p1->next;
//     p1->next = head;
//     head = p1;
//     // deal with other node
//     p1 = p1->next;   
//     while (p1->next && p1->next->next) {
//         ListNode *p2 = p1->next;
//         p1->next = p2->next;
//         ListNode *tmp = p2->next->next;
//         p2->next->next = p2;
//         p2->next = tmp;
//         p1 = p2;
//     }    
//     return head;
// }

// recursive version
ListNode* swapPairs(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *p1 = head->next;
    head->next = p1->next;
    p1->next = head;
    head = p1;
    head->next->next = swapPairs(head->next->next);
    return head;
}

int main() {
    vector<int> v1 = {1, 2, 3};
    ListNode *l1 = new ListNode(v1[0]), *p1 = l1;
    for (int i = 1; i < v1.size(); i++) {
        ListNode *tmp = new ListNode(v1[i]);
        p1->next = tmp;
        p1 = p1->next;
    }
    p1 = swapPairs(l1);
    while(p1) {
        cout << p1->val << "\t";
        p1 = p1->next;
    }
    system("pause");
    return 0;
}
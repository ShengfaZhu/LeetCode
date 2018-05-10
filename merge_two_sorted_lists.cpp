// Merge two sorted linked lists and return it as a new list. 
// The new list should be made by splicing together the 
// nodes of the first two lists.
// Example:
// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(NULL) {} 
}; 

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    int first;
    ListNode *p1 = l1, *p2 = l2;
    if (p1->val < p2->val) {
        first = p1->val;
        p1 = p1->next;
    }
    else {
        first = p2->val;
        p2 = p2->next;
    }
    ListNode *ans = new ListNode(first);
    ListNode *p = ans;
    while(p1 || p2) {  
        if (p1 == NULL) {
            p->next = p2;
            break;
        }
        if (p2 == NULL) {
            p->next = p1;
            break;
        }
        if (p1->val < p2->val) {
            ListNode *tmp = new ListNode(p1->val);
            p->next = tmp;
            p = p->next; 
            p1 = p1->next;
        }
        else {
            ListNode *tmp = new ListNode(p2->val);
            p->next = tmp;
            p = p->next; 
            p2 = p2->next;
        }   
    }
    return ans;
}

int main() {
    vector<int> v1 = {1, 2, 4}, v2 = {1, 3, 4};
    ListNode *l1 = new ListNode(v1[0]), *l2 = new ListNode(v2[0]);
    ListNode *p1 = l1, *p2 = l2;
    for (int i = 1; i < v1.size(); i++) {
        ListNode *tmp = new ListNode(v1[i]);
        p1->next = tmp;
        p1 = p1->next;
    }    
    for (int i = 1; i < v2.size(); i++) {
        ListNode *tmp = new ListNode(v2[i]);
        p2->next = tmp;
        p2 = p2->next;
    }
    ListNode *h = mergeTwoLists(l1, l2), *p = h;
    while(p) {
        cout << p->val << "\t";
        p = p->next;
    } 
    cout << endl;
    system("pause");
    return 0;
}
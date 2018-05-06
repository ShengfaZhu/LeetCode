//You are given two non-empty linked lists representing two non-negative 
//integers. The digits are stored in reverse order and each of their nodes
//contain a single digit. Add the two numbers and return it as a linked list.
//Example:
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8
//Explanation: 342 + 465 = 807.

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(NULL) {} 
}; 

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode *p1 = l1, *p2 = l2;
	int temp_sum = p1->val + p2->val, step = 0, next_step = 0;
	if (temp_sum >= 10) {
		temp_sum = temp_sum - 10;
		next_step = 1;
	}
	ListNode *sum = new ListNode(temp_sum + step), *p = sum;
	p1 = p1->next, p2 = p2->next;
	while (!(p1 == NULL && p2 == NULL && next_step == 0))
	{
		step = next_step;
		temp_sum = (p1 != NULL ? p1->val : 0) + (p2 != NULL ? p2 ->val : 0) + step;
		if (temp_sum >= 10) {
			temp_sum = temp_sum - 10;
			next_step = 1;
		}
		else
			next_step = 0;
		p->next = new ListNode(temp_sum);
		p1 = p1 != NULL ? p1->next : p1;
		p2 = p2 != NULL ? p2->next : p2;
		p = p->next;
	}
	return sum;
}


int main() {
	int a[] = {1}, b[] = {9, 9, 9};
	ListNode *l1 = new ListNode(a[0]);
	ListNode *l2 = new ListNode(b[0]);
	ListNode *curr = l1;
	//for(int i = 1; i < 3; i++) {
	//	curr->next = new ListNode(a[i]);
	//	curr = curr->next;
	//}
	curr = l2;
	for(int i = 1; i < 3; i++) {
		curr->next = new ListNode(b[i]);
		curr = curr->next;
	}
	ListNode *sum = addTwoNumbers(l1, l2);
	ListNode *p = sum;
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	system("pause");
	return 0;
}

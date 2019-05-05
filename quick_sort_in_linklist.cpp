#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

int patition(vector<int>* nums, int low, int high) {
    if (low == high) {
        return low;
    }
    int i = rand() % (high - low + 1) + low;
    int pivot = nums->at(i);
    swap(nums->at(i), nums->at(low));
    while (low < high) {
        while (high > low && pivot <= nums->at(high)) {
            high--;
        }
        nums->at(low) = nums->at(high);
        while(high > low && nums->at(low) <= pivot){
            low++;
        }
        nums->at(high) = nums->at(low);
    }
    nums->at(low) = pivot;
    return low;
}

void quickSort(vector<int>* nums, int low, int high) {
    if (nums->empty() || low >= high) {
        return;
    }
    int index = patition(nums, low, high);
    quickSort(nums, low, index);
    quickSort(nums, index + 1, high);
}

struct ListNode
{
    int value;
    ListNode* next;
    ListNode(int v) : value(v), next(nullptr) {}
};

ListNode* patition(ListNode* begin, ListNode* end) {
    if (begin == end) {
        return begin;
    }
    int pivot = begin->value;
    ListNode* slow = begin, *fast = begin->next;
    while (fast != end) {
        if (fast->value < pivot) {
            slow = slow->next;
            swap(slow->value, fast->value);
        }
        fast = fast->next;
    }
    swap(begin->value, slow->value);
    return slow;
}

void quickSort(ListNode* head, ListNode* end) {
    if (head == end || head == nullptr) {
        return;
    }
    ListNode* pivot = patition(head, end);
    quickSort(head, pivot);
    quickSort(pivot->next, end);
}

int main() {
    vector<int> nums = {4, 2, 5, 3, 7, 9, 0, 1};
    ListNode* head = new ListNode(nums[0]), *p = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        ListNode* curr = new ListNode(nums[i]);
        p->next = curr;
        p = p->next;
    }
    quickSort(head, nullptr);
    p = head;
    while (p) {
        cout << p->value << "\t";
        p = p->next;
    }
    system("pause");
    return 0;
}
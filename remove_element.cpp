// Given an array nums and a value val, remove all instances 
// of that value in-place and return the new length.
// Do not allocate extra space for another array, you must 
// do this by modifying the input array in-place with O(1) extra memory.
// The order of elements can be changed. It doesn't 
// matter what you leave beyond the new length.
// Example 1:
// Given nums = [3,2,2,3], val = 3,
// Your function should return length = 2, 
// with the first two elements of nums being 2.
// It doesn't matter what you leave beyond the returned length.

#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    if (nums.empty())
        return 0;
    int pre = 0, last = nums.size() - 1;
    while (pre < last) {
        if (nums[pre] == val && nums[last] != val) {
            nums[pre] = nums[last];
            nums[last] = val;
            pre++;
            last--;
        }
        if (nums[pre] != val)
            pre++;
        if (nums[last] == val)
            last--;

    }
    if (pre == last && nums[pre] != val)
        return pre + 1;
    return pre;
}

int main() {
    vector<int> nums = {1};
    int val = 1;
    int len = removeElement(nums, val);
    cout << "length : " << len << endl;
    for (int i = 0; i < nums.size(); i++) 
        cout << nums[i] << endl;
    system("pause");
    return 0;
}

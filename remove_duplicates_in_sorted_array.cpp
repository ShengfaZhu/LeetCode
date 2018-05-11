// Given a sorted array nums, remove the duplicates in-place 
// such that each element appear only once and return the new length.
// Do not allocate extra space for another array, you must do this 
// by modifying the input array in-place with O(1) extra memory.
// Example 1:
// Given nums = [1,1,2],
// Your function should return length = 2, with the first two 
// elements of nums being 1 and 2 respectively.
// It doesn't matter what you leave beyond the returned length.

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 1) 
        return 1;
    if (nums.empty())
        return 0;
    int len = 0;
    int i = 1;
    while (i < nums.size()) {
        if (nums[i] != nums[len]) {
            len++;
            nums[len] = nums[i];
        }
        i++;       
    }
    return len + 1;
}

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int len = removeDuplicates(nums);
    cout << "length : " << len << endl;
    for (int i = 0; i < nums.size(); i++) 
        cout << nums[i] << endl;
    system("pause");
    return 0;
}
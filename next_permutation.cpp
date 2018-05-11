// Implement next permutation, which rearranges numbers 
// into the lexicographically next greater permutation of numbers.
// If such arrangement is not possible, it must rearrange it as t
// he lowest possible order (ie, sorted in ascending order).
// The replacement must be in-place and use only constant extra memory.
// Here are some examples. Inputs are in the left-hand column and 
// its corresponding outputs are in the right-hand column.
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

#include <iostream>
#include <vector>
using namespace std;

void nextPermutation(vector<int>& nums) {
    for (int i = nums.size() - 1; i > 0 ; i--) {
        if (nums[i] > nums[i - 1]) {
            int tmp = nums[i - 1];
            nums[i - 1] = nums[i];
            nums[i] = tmp;
            return;
        }
    }
    // reverse into ascending order
    int sz = nums.size();
    for (int i = 0; i < sz/ 2; i++) {
        int tmp = nums[sz - i - 1];
        nums[sz - i - 1] = nums[i];
        nums[i] = tmp;
    }
}

int main() {
    vector<int> nums = {3, 2, 1};
    nextPermutation(nums);
    for (int& num : nums)
        cout << num << endl;
    system("pause");
    return 0;
}

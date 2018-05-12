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
#include <algorithm>
#include <vector>
using namespace std;

void nextPermutation(vector<int>& nums) {
    if (nums.empty())
        return;
    int i = nums.size() - 2;
    // 从后向前找到第一个降序排列的数，并记录其中的最小值
    while(i >= 0 && nums[i] >= nums[i + 1]) {        
        i--;
    }
    cout << "i: " << i << endl;
    if (i < 0) {//原数列为从前至后的降序
        sort(nums.begin(), nums.end());
        return;
    }
    else {
        int j = i + 1;
        while (j < nums.size() && nums[j] > nums[i]) {
            j++;
        }
        cout << "i : " << i << "\n" << "j : " << j << "\n";
        int tmp = nums[i];
        nums[i] = nums[j - 1];
        nums[j - 1] = tmp;
        sort(nums.begin() + i + 1, nums.end());
        return;
    }
}

int main() {
    vector<int> nums = {5, 1, 1};
    nextPermutation(nums);
    for (int& num : nums)
        cout << num << endl;
    system("pause");
    return 0;
}
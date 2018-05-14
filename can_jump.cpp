// Given an array of non-negative integers, 
// you are initially positioned at the first index of the array.
// Each element in the array represents your 
// maximum jump length at that position.
// Determine if you are able to reach the last index.
// Example 1:
// Input: [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, 
// then 3 steps to the last index

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// bool backtrack(vector<int>& nums, int k) {
//     if (k == nums.size() - 1) {
//         return true;
//     }
//     if (k > nums.size() - 1) {
//         return false;
//     }
//     bool flag = false;
//     for (int i = 1; i <= nums[k]; i++) {
//         flag = flag || backtrack(nums, k + i);
//         if (flag) return flag;
//     }
//     return flag;
// }

// unblievable solution
bool canJump(vector<int>& nums) {
    int i = 0;
    for (int reach = 0; i < nums.size() && i <= reach; i++) {
        cout << i << endl;
        reach = max(i + nums[i], reach);
    }
    return i == nums.size();
}

int main() {
    vector<int> nums = {2,3,1,1,4};
    cout << canJump(nums) << endl;
    system("pause");
    return 0;
}
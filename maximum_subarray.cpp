// Given an integer array nums, find the contiguous subarray 
// (containing at least one number) which has the largest 
// sum and return its sum.
// Example:
// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Kadane's algorithm
int maxSubArray(vector<int>& nums) {
    if (nums.empty())
        return 0;
    int max_end_here = nums[0], max_so_far = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        max_end_here = max(max_end_here + nums[i], nums[i]);
        max_so_far = max(max_end_here, max_so_far);
    }
    return max_so_far;
}

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums) << endl;
    system("pause");
    return 0;
}
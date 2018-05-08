// Given an array nums of n integers and an integer target, 
// find three integers in nums such that the sum is closest to target. 
// Return the sum of the three integers. 
// You may assume that each input would have exactly one solution.

// Example:
// Given array nums = [-1, 2, 1, -4], and target = 1.
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).


#include <iostream>
#include <vector>
#include <limits.h>
#include <cmath>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    if (nums.size() < 3)
        return 0;
    sort(nums.begin(), nums.end());
    int i = 0, closest_sum = INT_MIN;
    while (i < nums.size() - 2) {
        //skip the repeated number
        if (i - 1 >= 0 && nums[i] == nums[i - 1]) {
            i++;
            continue;
        }
        int j = i + 1, k = nums.size() - 1;
        while (j < k) {
            int temp_sum = nums[i] + nums[j] + nums[k];
            if (closest_sum == INT_MIN || abs(temp_sum - target) < abs(closest_sum - target)) {
                closest_sum = temp_sum;
            }
            if (temp_sum == target) {
                return target;
            }
            else if (temp_sum < target) {
                j++;
            }
            else {
                k--;
            }
        }
        i++;
    }
    return closest_sum;
}

int main() {
    vector<int> nums = {0, 1, 2};
    int target = 0;
    cout << threeSumClosest(nums, target) << endl;
    system("pause");
    return 0;
}
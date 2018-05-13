// Given an array of integers nums sorted in ascending order, 
// find the starting and ending position of a given target value.
// Your algorithm's runtime complexity must be in the order of O(log n).
// If the target is not found in the array, return [-1, -1].
// Example 1:
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> range(2, -1);
    if (nums.empty())
        return range;
    if (nums.size() == 1 && nums[0]== target) {
        return vector<int>(2, 0);
    }
    int low = 0, high = nums.size() - 1, ind = -1;
    while(low < high) {
        if (nums[low] == target) {
            ind = low;
            break;
        }
        if (nums[high] == target) {
            ind = high;
            break;
        }
        int mid = (low + high) / 2;
        if (nums[mid] == target) {
            ind = mid;
            break;
        }
        if (nums[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    // not found
    if (ind == -1)
        return range;
    // found, get range
    int i = ind;
    while (i >= 1 && nums[i - 1] == target)
        i = i - 1;
    range[0] = i;
    i = ind;
    while (i <= nums.size() - 2 && nums[i + 1] == target)
        i = i + 1;
    range[1] = i;
    return range;
}

int main() {
    vector<int> nums = {8};
    int target = 8;
    vector<int> range = searchRange(nums, target);
    for (int& i : range) 
        cout << i << "\t";
    system("pause");
    return 0;
}
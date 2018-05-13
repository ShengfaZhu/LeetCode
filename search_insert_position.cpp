// Given a sorted array and a target value, 
// return the index if the target is found. 
// If not, return the index where it would 
// be if it were inserted in order.
// You may assume no duplicates in the array.

#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    if (nums.empty()) {
        return 0;
    }
    int low = 0, high = nums.size() - 1, ind = -1;
    if (nums[low] > target) {
        return 0;
    }
    if (nums[high] < target) {
        return nums.size();
    }
    while(low <= high) {
        if (nums[low] == target) {
            return low;
        }
        if (nums[high] == target) {
            return high;
        }
        int mid = (low + high) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            low = mid + 1;
        }
        else 
            high = mid - 1;
    }
    high = high < 0 ? 0 : high;
    cout << high << endl;
    while (high < nums.size() && nums[high] < target)
        high++;
    return high;
        
}

int main() {
    vector<int> nums = {1,3,5,6};
    int target = 0;
    cout << searchInsert(nums, target) << endl;
    system("pause");
    return 0;
}